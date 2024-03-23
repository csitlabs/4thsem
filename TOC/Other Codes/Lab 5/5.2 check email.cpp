// Lab 5.2 WAP to validate email address


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void state(char *str) {
    char f = 'a';

    for (int i = 0; str[i] != '\0'; i++) {
        switch (f) {
            case 'a': // start
                if (isalpha(str[i]) || (str[i] >= '0' && str[i] <= '9'))
                    f = 'b';
                break;
            case 'b': // username
                if (isalpha(str[i]) || (str[i] >= '0' && str[i] <= '9') || str[i] == '_' || str[i] == '.' || str[i] == '-')
                    f = 'b';
                else if (str[i] == '@')
                    f = 'c';
                break;
            case 'c': // at
                if (isalpha(str[i]) || (str[i] >= '0' && str[i] <= '9'))
                    f = 'e';
                break;
            case 'e': // domain
                if (isalpha(str[i]) || (str[i] >= '0' && str[i] <= '9') || str[i] == '_' || str[i] == '-')
                    f = 'e';
                else if (str[i] == '.')
                    f = 'g';
                break;
            case 'g': // DOT
                if (isalpha(str[i]) || (str[i] >= '0' && str[i] <= '9'))
                    f = 'h';
                break;
            case 'h': // TOP level domain
                if (isalpha(str[i]) || (str[i] >= '0' && str[i] <= '9'))
                    f = 'h';
                break;
        }
    }

    if (f == 'h')
        printf("Email address: %s is valid.\n", str);
    else
        printf("Email address: %s is not valid.\n", str); 
}

int main() {
    char str[100];
    int n;

    printf("Validate email.\n");
    
    while (1) {
        printf("\nEnter an email address to be checked: ");
        scanf("%s", str);
        state(str);

        printf("Enter 1 to Continue or 0 to Exit: ");
        scanf("%d", &n);

        if (n == 0)
            break;
    }

    return 0;
}

