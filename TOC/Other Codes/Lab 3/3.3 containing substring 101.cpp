// 3.3 WAP to implement NFA over {0,1} and accepts all strings containing substring 101

#include <stdio.h>

// NFA transition function
int transition(int state, char input) {
    switch (state) {
        case 0:
            return (input == '1') ? 1 : 0; // Move to state q1 for '1', stay in state q0 for '0'
        case 1:
            return (input == '0') ? 2 : (input == '1') ? 1 : 0; // Move to state q2 for '0', stay in state q1 for '1'
        case 2:
            return (input == '1') ? 3 : 0; // Move to state q3 for '1', stay in state q0 for '0'
        case 3:
            return (input == '0') ? 2 : (input == '1') ? 1 : 0; // Move to state q2 for '0', stay in state q1 for '1'
        default:
            return -1; // Invalid state
    }
}

// NFA acceptance function
int isAccepted(char *input) {
    int currentState = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        currentState = transition(currentState, input[i]);
        if (currentState == 3) {
            // Accept early if the substring "101" is found
            return 1;
        }
    }

    return (currentState == 3); // Accept if the final state is q3
}

int main() {
    char input[100];
    char choice;

    printf("Implement NFA over {0,1} and accepts all strings containing substring 101");
    do {
        printf("\n\nEnter a string over {0,1}: ");
        scanf("%s", &input);

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

