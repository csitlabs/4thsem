// 2.3 WAP to implement DFA over {0,1} that accepts all strings containing 01 as substring

#include <stdio.h>

// DFA transition function
int transition(int state, char input) {
    switch (state) {
        case 0:
            return (input == '0') ? 1 : 0;
        case 1:
            return (input == '1') ? 2 : (input == '0') ? 1 : 0;
        case 2:
            return (input == '0') ? 3 : 0;
        case 3:
            return (input == '1') ? 2 : (input == '0') ? 1 : 0;
        default:
            return -1; // Invalid state
    }
}

// DFA acceptance function
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

	printf("Implement DFA over {0,1} that accepts all strings containing 01 as substring");
    do {
        printf("\nEnter a string over {0,1}: ");
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

