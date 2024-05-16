#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a term in a polynomial
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node with given coeff and exp
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

struct Node* inputValuesOfTerms(){
	int size;
	printf("Enter the no of terms of the polynomial in ascending/descending order of their exp: ");
	scanf("%d", &size);
	struct Node* p=NULL;
	for(int i=0; i<size; i++){
		printf("Term %d: Coeff: ", i+1);
		int c;
		scanf("%d", &c);
		printf("Term %d: Exp: ", i+1);
		int e;
		scanf("%d", &e);
		struct Node* term=createNode(c, e);
		term->next=p;
		p=term;
	}
	return p;
}

// struct Node* addPolynomials(struct Node* p1, struct Node*  p2){
//     struct Node* result=NULL;
//     //if both are null
//     if(p1==NULL && p2==NULL){
//         return result;
//     }
//     //if one of them is null
//     if(p1==NULL){
//         result=p2;
//         return result;
//     }
//     if(p2==NULL){
//         result=p1;
//         return result;
//     }
//     struct Node* tail;
//     //if both are present
//     while(p1!=NULL && p2!=NULL){
//         if(p1->exp>p2->exp){
//             if(result==NULL){
//                 result=p1;
//                 tail=p1;
//                 p1=p1->next;
//             }
//             else{
//                 tail->next=p1;
//                 tail=p1;
//                 p1=p1->next;
//             }
//         }
//         else if(p2->exp>p1->exp){
//             if(result==NULL){
//                 result=p2;
//                 tail=p2;
//                 p2=p2->next;
//             }
//             else{
//                 tail->next=p2;
//                 tail=p2;
//                 p2=p2->next;
//             }
//         }
//         //exp are equal
//         else{
//             if(result==NULL){
//                 result=p1;
//                 tail=p1;
//                 tail->coeff+=p2->coeff;
//                 struct Node* delnode=p2;
//                 p1=p1->next;
//                 p2=p2->next;
//                 free(delnode);
//             }
//             else{
//                 tail->next=p1;
//                 tail=p1;
//                 tail->coeff+=p2->coeff;
//                 struct Node* delnode=p2;
//                 p1=p1->next;
//                 p2=p2->next;
//                 free(delnode);
//             }
//         }

//     }
//     if(p1!=NULL){
//         tail->next=p1;
//     }
//     if(p2!=NULL){
//         tail->next=p2;
//     }
//     return result;
// }

// Function to add two polynomials represented as linked lists
struct Node* addPolynomials(struct Node* p1, struct Node*  p2) {
    struct Node* result = NULL;
    struct Node* tail = NULL;

    while (p1 != NULL && p2 != NULL) {
        // struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        struct Node* newNode;
        if (p1->exp > p2->exp) {
            newNode = createNode(p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp) {
            newNode = createNode(p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else {
            newNode = createNode(p1->coeff+p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }

        // newNode->next = NULL;

        if (result == NULL) {
            result = newNode;
            tail = result;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    // Copy the remaining nodes from p1, if any
    while (p1 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = p1->coeff;
        newNode->exp = p1->exp;
        newNode->next = NULL;
        tail->next = newNode;
        tail = tail->next;
        p1 = p1->next;
    }

    // Copy the remaining nodes from p2, if any
    while (p2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = p2->coeff;
        newNode->exp = p2->exp;
        newNode->next = NULL;
        tail->next = newNode;
        tail = tail->next;
        p2 = p2->next;
    }

    return result;
}

// Function to display a polynomial represented as a linked list
void displayPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}
int main() {
    // Example polynomials: 3x^2 + 2x + 1 and 4x^3 + 5x^2 + 6x + 7
    struct Node* poly1 = inputValuesOfTerms();
    

    struct Node* poly2 = inputValuesOfTerms();


    // Display the original polynomials
    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    // Add the polynomials
    struct Node* result = addPolynomials(poly1, poly2);

    // Display the result
    printf("Sum of Polynomials: ");
    displayPolynomial(result);

    return 0;
}

