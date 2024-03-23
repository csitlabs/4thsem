// 1. WAP to find prefix, suffix, & substring of entered string

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int i, j, k, n, a;
    char string[10], string1[10];
    
    printf("Find prefix, suffix, & substring of entered string.\n");
    printf("Enter string of {a,b}: ");
    scanf("%s", string);
    
    n = strlen(string);
    
    printf("\n1. Prefix\t2. Suffix\t3. Is SubString??\t4. Exit\n");
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &a);

        switch(a) {
            case 1:
                // Prefix
                for (i = 0; i < n; i++) {
                    for (j = 0; j <= i; j++) {
                        printf("%c", string[j]);
                    }
                    printf("\n");
                }
                break;
                
            case 2:
                // Suffix
                for (i = n - 1; i >= 0; i--) {
                    for (j = n - 1; j >= i; j--) {
                        printf("%c", string[j]);
                    }
                    printf("\n");
                }
                break;
                
            case 3:
                // Substring
                printf("Enter string to check whether it's substring or not: ");
                scanf("%s", string1);
                if (strstr(string, string1) != NULL) {
                    printf("%s is a substring of %s.\n", string1, string);
                } else {
                    printf("%s is not a substring of %s.\n", string1, string);
                }
                break;
                
            case 4:
                exit(0);
                break;
                
            default:
                printf("Enter valid option!!!\n");
                break;
        }
    } while (a != 4);

    return 0;
}

