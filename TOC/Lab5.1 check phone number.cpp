// Lab 5.1 WAP to validate phone number


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void state(char *str) {
    char f = 'a';

    for (int i = 0; str[i] != '\0'; i++) {
        switch (f) {
            case 'a':
                if (str[i] == '9')
                    f = 'b';
                break;
            case 'b':
                if (str[i] == '8' || str[i] == '7')
                    f = 'c';
                break;
            case 'c':
                if (str[i] >= '0' && str[i] <= '9')
                    f = 'd';
                break;
            case 'd':
                if (str[i] >= '0' && str[i] <= '9')
                    f = 'e';
                break;
            case 'e':
                if (str[i] >= '0' && str[i] <= '9')
                    f = 'f';
                break;
            case 'f':
                if (str[i] >= '0' && str[i] <= '9')
                    f = 'g';
                break;
            case 'g':
                if (str[i] >= '0' && str[i] <= '9')
                    f = 'h';
                break;
            case 'h':
                if (str[i] >= '0' && str[i] <= '9')
                    f = 'i';
                break;
            case 'i':
                if (str[i] >= '0' && str[i] <= '9')
                    f = 'j';
                break;
            case 'j':
                if (str[i] >= '0' && str[i] <= '9')
                    f = 'k';
                break;
        }
    }

    if (f == 'k')
        printf("Phone number: %s is valid.\n", str);
    else
        printf("Phone number: %s is not valid.\n", str);
}

int main() {
    char str[100];
    int n;

here:
    printf("\nEnter the phone number to be checked: ");
    scanf("%s", str);

    if (strlen(str) > 10)
        goto here;

    state(str);

    do {
        printf("Enter 1 to Continue or 0 to Exit: ");
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
