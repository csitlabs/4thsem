//6.1 Convert RE to FA - 0*(1+0)001

// for accepting state input = 010 or 001100
// not accepting 10001

#include <stdio.h>
#include <stdlib.h>

void state(char *str) {
    char f = 'a';
    for (int i = 0; str[i] != '\0'; i++) {
        switch (f) {
            case 'a':
                if (str[i] == '0')
                    f = 'b';
                break;
            case 'b':
                if (str[i] == '0' || str[i] == '1')
                    f = 'b';
                if (str[i] == '1')
                    f = 'c';
                break;
            case 'c':
                if (str[i] == '0')
                    f = 'd';
                break;
        }
    }
    
    if (f == 'd')
        printf("String is accepted\n");
    else
        printf("String is not accepted\n");
}

int main() {
    char str[100];
    int n;
    printf("Convert RE to FA - 0*(1+0)001\n");
    while (1) {
        printf("\nEnter the string to be checked: ");
        scanf("%s", str);
        state(str);

        printf("Enter 1 to continue or 0 to exit: ");
        scanf("%d", &n);
        
        if (n == 0)
            break;
    }

    return 0;
}
