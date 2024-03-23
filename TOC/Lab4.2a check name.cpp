// Lab 4.2a WAP to implement NFA for text "Your Name"


#include <stdio.h>
#include <stdlib.h>

void state(char *str) {
    char f = '1';

    for (int i = 0; str[i] != '\0'; i++) {
        switch (f) {
            case '1':
                if (str[i] == 'b') //change this letters with your name
                    f = '2';
                break;
            case '2':
                if (str[i] == 'i')
                    f = '3';
                break;
            case '3':
                if (str[i] == 'm')
                    f = '4';
                break;
            case '4':
                if (str[i] == 'o')
                    f = '5';
                break;
        }
    }

    if (f == '5')
        printf("Name: %s is accepted.\n", str);
    else
        printf("Name: %s is not accepted.\n", str);
}

int main() {
    char str[10];
    int n;

here:
    printf("\nEnter name to be checked: ");
    scanf("%s", str);
    state(str);

    do {
        printf("Enter 1 to continue or 0 to Exit: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                goto here;
                break;
            case 0:
                exit(0);
                break;
        }

    } while (n != 0);

    return 0;
}

