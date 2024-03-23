// Construct PDA 

// accepting input = 01001
// not accepting = 1001
#include <stdio.h>
#include <stdlib.h>

void state(char *str) { 
    char f = 'a';
    char g = 'a'; // Variable g is introduced for tracking the count of 'b's
    for (int i = 0; str[i] != '\0'; i++) {
        switch (f) {
            case 'a':
                if (str[i] == '0')
                    f = 'b';
                else
                    printf("String is not accepted\n");
                break;
            case 'b':
                if (str[i] == '0') {
                    f = 'b';
                    g = 'a'; // Reset the count of 'b's when encountering '0'
                }
                else if (str[i] == '1') {
                    f = 'c';
                    g = 'b'; // Increment the count of 'b's when encountering '1'
                }
                else
                    printf("String is not accepted\n");
                break;
            case 'c':
                if (str[i] == '0') {
                    if (g == 'b') // Check if the count of 'b's is greater than 0
                        f = 'd';
                    else
                        printf("String is not accepted\n");
                }
                else
                    printf("String is not accepted\n");
                break;
        }
    }
   
    if (f == 'd')
        printf("String is accepted\n");
}

int main() {
    char str[100];
    int n;
    printf("Construct PDA\n");
    do {
        printf("\nEnter the string to be checked: ");
        scanf("%s", str);
        state(str);

        printf("Enter 1 to continue or 0 to exit: ");
        scanf("%d", &n);
    } while (n != 0);

    return 0;
}
