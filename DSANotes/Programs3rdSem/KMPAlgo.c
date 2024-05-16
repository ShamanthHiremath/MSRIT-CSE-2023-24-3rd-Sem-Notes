#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

void computeLPS(char* pattern, int M, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(char* text, char* pattern) {

    int N = strlen(text);
    int M = strlen(pattern);

    int* lps = (int*)malloc(M * sizeof(int));

    computeLPS(pattern, M, lps);
    for(int i=0; i<M; i++){
        printf("%d  ", lps[i]);
    }

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < N) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("\nPattern found at index %d\n", i - j);
            j = lps[j - 1];
        }
        
        else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    free(lps);
}

void nFind(char* text, char*pattern){
    printf("NFind() results: \n");
    int endmatch=strlen(pattern)-1;
    int patlast=strlen(pattern)-1;
    int textlast=strlen(text)-1;
    // int i=0, j=0;
    int i, j;
    int start=0;
    bool check=0;
    for(i=0; endmatch<=textlast; start++, endmatch++){
        if(pattern[patlast]==text[endmatch]){

            for(j=0, i=start; j<patlast && pattern[j]==text[i]; i++, j++);

            if(j==patlast){
                printf("Found substr at: %d\n", start);
                check=1;
            }
        }
    }
    if(!check){
        printf("Substr not found\n");
    }
}

int main() {
    char text[100], pattern[50];

    printf("Enter the text: ");
    scanf("%s", text);  // Read up to 99 characters until newline (excluding newline)
    //getchar();  // Consume the newline character

    printf("Enter the pattern: ");
    scanf("%s", pattern);  // Read up to 49 characters until newline (excluding newline)
    //getchar();  // Consume the newline character

    nFind(text, pattern);

    KMP(text, pattern);

    return 0;
}