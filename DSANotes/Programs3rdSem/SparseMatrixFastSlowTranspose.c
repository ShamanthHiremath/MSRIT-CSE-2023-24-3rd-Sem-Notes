#include <stdio.h>
#include <stdlib.h>
/*
Sparse matrix is a matrix consisting of more no of elements as 0
ARRAY is
{ {1, 0, 3},
   {0, 2, 0},
   {0, 0, 4} }; 
Original Matrix:

Rows: 3, Cols: 3, Elements: 4
Elements:
(0, 0, 1)
(1, 1, 2)
(2, 0, 3)
(2, 2, 4)

Slow Transposed Matrix:

Rows: 3, Cols: 3, Elements: 4
Elements:
(0, 0, 1)
(1, 1, 2)
(0, 2, 3)
(2, 2, 4)

Fast Transposed Matrix:

Rows: 3, Cols: 3, Elements: 4
Elements:
(0, 0, 1)
(0, 2, 3)
(1, 1, 2)
(2, 2, 4)
*/



// Structure to represent a sparse matrix element
struct Element {
    int row;
    int col;
    int value;
};

// Structure to represent a sparse matrix
struct SparseMatrix {
    int rows;
    int cols;
    int numElements;
    struct Element *elements;
};

// Function to perform slow transpose on a sparse matrix
struct SparseMatrix slowTranspose(struct SparseMatrix matrix) {
    struct SparseMatrix result;
    result.rows = matrix.cols;
    result.cols = matrix.rows;
    result.numElements = matrix.numElements;
    result.elements = (struct Element *)malloc(result.numElements * sizeof(struct Element));

    // Swap rows and columns in the transposed matrix
    for (int i = 0; i < matrix.numElements; i++) {
        result.elements[i].row = matrix.elements[i].col;
        result.elements[i].col = matrix.elements[i].row;
        result.elements[i].value = matrix.elements[i].value;
    }

    return result;
}

// Function to perform fast transpose on a sparse matrix
struct SparseMatrix fastTranspose(struct SparseMatrix matrix) {
    struct SparseMatrix result;
    result.rows = matrix.cols;
    result.cols = matrix.rows;
    result.numElements = matrix.numElements;
    result.elements = (struct Element *)malloc(result.numElements * sizeof(struct Element));

    // Array to store the number of elements in each column of the original matrix with 0 value
    int *numInCol = (int *)calloc(matrix.cols, sizeof(int));

    // Calculate the number of elements in each column of the original matrix
    for (int i = 0; i < matrix.numElements; i++) {
        numInCol[matrix.elements[i].col]++;
    }

    // Calculate the starting position of each column in the result matrix
    int *startPos = (int *)malloc(matrix.cols * sizeof(int));
    startPos[0] = 0;
    for (int i = 1; i < matrix.cols; i++) {
        //basically stores the starting position of the row of transposed matrix to be added in the fast transpose matrix
        startPos[i] = startPos[i - 1] + numInCol[i - 1];
    }

    // Place elements in the transposed matrix at the correct positions
    for (int i = 0; i < matrix.numElements; i++) {
        int col = matrix.elements[i].col;
        int pos = startPos[col];
        result.elements[pos].row = matrix.elements[i].col;
        result.elements[pos].col = matrix.elements[i].row;
        result.elements[pos].value = matrix.elements[i].value;
        startPos[col]++;
    }

    free(numInCol);
    free(startPos);
    return result;
}

// Function to print a sparse matrix
void printSparseMatrix(struct SparseMatrix matrix) {
    printf("Rows: %d, Cols: %d, Elements: %d\n", matrix.rows, matrix.cols, matrix.numElements);
    printf("Elements:\n");
    for (int i = 0; i < matrix.numElements; i++) {
        printf("(%d, %d, %d)\n", matrix.elements[i].row, matrix.elements[i].col, matrix.elements[i].value);
    }
}
struct SparseMatrix inputSparseMatrix(){
    struct SparseMatrix matrix;
    printf("\nENTER THE DETAILS OF YOU INPUT SPARSE MATRIX\n");
    printf("No of rows: ");
    scanf("%d", &matrix.rows);
    printf("No of cols: ");
    scanf("%d", &matrix.cols);
    printf("No of elements: ");
    scanf("%d", &matrix.numElements);
    matrix.elements = (struct Element *)malloc(matrix.numElements * sizeof(struct Element));
    printf("Enter matrix elements in the format (row, col, value) (with one space each):\n\n");
    for (int i = 0; i < matrix.numElements; i++) {
        printf("ELEMENT %d (ROW COL ELEMENT) : ", i+1);
        scanf("%d %d %d", &matrix.elements[i].row, &matrix.elements[i].col, &matrix.elements[i].value);
    }
    printf("\n");
    return matrix;
}

int main() {
    // struct SparseMatrix originalMatrix;
    // originalMatrix.rows = 3;
    // originalMatrix.cols = 3;
    // originalMatrix.numElements = 4;
    // originalMatrix.elements = (struct Element *)malloc(originalMatrix.numElements * sizeof(struct Element));

    // // Example sparse matrix
    // originalMatrix.elements[0] = (struct Element){0, 0, 1};
    // originalMatrix.elements[1] = (struct Element){1, 1, 2};
    // originalMatrix.elements[2] = (struct Element){2, 0, 3};
    // originalMatrix.elements[3] = (struct Element){2, 2, 4};
    struct SparseMatrix originalMatrix =inputSparseMatrix();

    printf("Original Matrix:\n\n");
    printSparseMatrix(originalMatrix);

    // Slow transpose
    struct SparseMatrix slowTransposedMatrix = slowTranspose(originalMatrix);
    printf("\nSlow Transposed Matrix:\n\n");
    printSparseMatrix(slowTransposedMatrix);

    // Fast transpose
    struct SparseMatrix fastTransposedMatrix = fastTranspose(originalMatrix);
    printf("\nFast Transposed Matrix:\n\n");
    printSparseMatrix(fastTransposedMatrix);

    // Cleanup
    free(originalMatrix.elements);
    free(slowTransposedMatrix.elements);
    free(fastTransposedMatrix.elements);

    return 0;
}
//   printf("Enter row no: ");
//         scanf("%d", &matrix.elements[i].row);
//         printf("Enter col no: ");
//         scanf("%d", &matrix.elements[i].col);
//         printf("Enter element: ");
//         scanf("%d", &matrix.elements[i].value);