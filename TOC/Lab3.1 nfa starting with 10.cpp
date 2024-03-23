// 3.1 WAP to implement NFA over {0,1} and accepts all strings that starts with 10

#include <stdio.h>
#include <stdlib.h>

void state(char *str) { 
    char f = '1', g = '1';

    for (int i = 0; str[i] != '\0'; i++) {
        switch (f) {
            case '1':
                if (str[i] == 'b')
                    f = '2';
                break;
                
            case '2':
                if (str[i] == 'b' || str[i] == 'a') 
                    f = '3';
                break;
                
            case '3':
                if (str[i] == 'a')  
                    f = '1';
                else if (str[i] == 'b') {
                    f = '2';
                    g = '3';
                }
                break;
        }
    }
   
    if (f == '3' || g == '3')
        printf("String is accepted\n");
    else
        printf("String is not accepted\n");
}

int main() {
    char str[100];
    int n;

here: 
    printf("\nEnter the string to be checked: ");
    scanf("%s", str);
    state(str);

    do {
        printf("Enter 1: continue or 0: Exit ");
        scanf("%d", &n);
        
        switch(n) {
            case 1:
                goto here;
                break;
            case 0:
                exit(0);
                break;
        }

    } while(n != 0);

    return 0;
}

