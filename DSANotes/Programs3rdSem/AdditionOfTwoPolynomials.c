#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a term in a polynomial
typedef struct Term {
    int coefficient;
    int exponent;
}Term;

// Define a structure to represent a polynomial
struct Polynomial {
    int num_terms;
    Term *terms;
};

// Function to input a polynomial
void inputPolynomial(struct Polynomial *poly) {
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &poly->num_terms);

    poly->terms = (struct Term *)malloc(poly->num_terms * sizeof(struct Term));

    printf("Enter the terms (coefficient and exponent) of the polynomial:\n");
    for (int i = 0; i < poly->num_terms; ++i) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly->terms[i].coefficient, &poly->terms[i].exponent);
    }
}

// Function to display a polynomial
void displayPolynomial(const struct Polynomial *poly) {
    for (int i = 0; i < poly->num_terms; ++i) {
        printf("%dx^%d", poly->terms[i].coefficient, poly->terms[i].exponent);
        
        if (i < poly->num_terms - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}


//NOT REQUIRED
// struct Term* createTerm(int coeff, int exp){
//     struct Term* newTerm=(struct Term*)malloc(sizeof(struct Term));
//     newTerm->coefficient=coeff;
//     newTerm->exponent=exp;
//     return newTerm;

// }

// Function to add two polynomials
struct Polynomial addPolynomials(const struct Polynomial *poly1, const struct Polynomial *poly2) {
    struct Polynomial result;
    result.num_terms = poly1->num_terms + poly2->num_terms;
    result.terms = (struct Term *)malloc(result.num_terms * sizeof(struct Term));

    int i = 0, j = 0, k = 0;
    while (i < poly1->num_terms && j < poly2->num_terms) {
        if (poly1->terms[i].exponent > poly2->terms[j].exponent) {
            result.terms[k] = poly1->terms[i];
            i++;
        }
        else if (poly1->terms[i].exponent < poly2->terms[j].exponent) {
            result.terms[k] = poly2->terms[j];
            j++;
        }
        else {
            result.terms[k].coefficient = poly1->terms[i].coefficient + poly2->terms[j].coefficient;
            result.terms[k].exponent = poly1->terms[i].exponent;
            j++;
            i++;
        }
        k++;
    }

    // Copy the remaining terms from poly1, if any
    while (i < poly1->num_terms) {
        result.terms[k++] = poly1->terms[i++];
    }

    // Copy the remaining terms from poly2, if any
    while (j < poly2->num_terms) {
        result.terms[k++] = poly2->terms[j++];
    }

    // Reallocate memory to fit the exact number of terms in the result
    result.terms = (struct Term *)realloc(result.terms, k * sizeof(struct Term));
    result.num_terms = k;

    return result;
}

int main() {
    struct Polynomial poly1, poly2, result;

    printf("Enter the first polynomial:\n");
    inputPolynomial(&poly1);

    printf("Enter the second polynomial:\n");
    inputPolynomial(&poly2);

    printf("\nPolynomial 1: ");
    displayPolynomial(&poly1);

    printf("Polynomial 2: ");
    displayPolynomial(&poly2);

    result = addPolynomials(&poly1, &poly2);

    printf("\nResult of addition: ");
    displayPolynomial(&result);

    // Free the memory allocated for terms arrays
    free(poly1.terms);
    free(poly2.terms);
    free(result.terms);

    return 0;
}
