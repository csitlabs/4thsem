// 1. WAP to find prefix, suffix, & substring of entered string

#include <stdio.h>
#include <string.h>

void prefix(char string[]);
void suffix(char string[]);
void substring(char string[], int x, int y);

int main() {
    char string[20];
    int i, j;
    printf("\nEnter a string: ");
    gets(string);
    printf("\nPrefixes: ");
    prefix(string);
    printf("\nSuffixes: ");
    suffix(string);
    printf("\nEnter i & j for substring: ");
    scanf("%d%d", &i, &j);
    substring(string, i, j);
    return 0;
}

void prefix(char string[]) {
    int i, j;
    char prefix[20];
    for (i = strlen(string); i >= 0; i--) {
        for (j = 0; j < i; j++) {
            prefix[j] = string[j];
        }
        prefix[j] = '\0';  // Use null character to indicate the end of the string
        printf("\n%s", prefix);
    }
}

void suffix(char string[]) {
    int i, j, k;
    char suffix[20];
    for (i = 0; i < strlen(string); i++) {
        k = i;
        for (j = 0; j < strlen(string); j++) {
            suffix[j] = string[k];
            k++;
        }
        suffix[j] = '\0';  // Use null character to indicate the end of the string
        printf("\n%s", suffix);
    }
}

void substring(char string[], int x, int y) {
    char substr[20];
    int index = 0;
    for (int i = x; i <= y; i++) {
        substr[index] = string[i];
        index++;
    }
    substr[index] = '\0';  // Use null character to indicate the end of the string
    printf("\nSubstring: %s", substr);
}

