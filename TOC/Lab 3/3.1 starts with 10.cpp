// 3.1 WAP to implement NFA over {0,1} and accepts all strings that starts with 10

#include <stdio.h>

// NFA transition function
int transition(int state, char input) {
    switch (state) {
        case 0:
            return (input == '1') ? 1 : 0;
        case 1:
            return (input == '0') ? 2 : 0;
        case 2:
            return 2; // Stay in state q2 for any input
        default:
            return -1; // Invalid state
    }
}

// NFA acceptance function
int isAccepted(char *input) {
    int currentState = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        currentState = transition(currentState, input[i]);
    }

    return (currentState == 2); // Accept if the final state is q2
}

int main() {
    char input[100];
    char choice;
    
    printf("Implement NFA over {0,1} and accepts all strings that starts with 10");

    do {
        printf("\n\nEnter a string over {0,1}: ");
        scanf("%s", input);

        if (isAccepted(input)) {
            printf("Accepted\n");
        } else {
            printf("Not Accepted\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume the newline character

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

