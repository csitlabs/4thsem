// Construct PDA
// accepting 001100
// non accepting 11010011

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAccepted(char *str) {
    int len = strlen(str);
    int mid = len / 2; // Calculate the midpoint of the string

    // Check if the length is even and not empty
    if (len % 2 == 0 && len > 0) {
        for (int i = 0; i < mid; i++) {
            // Check if characters at corresponding positions are equal
            if (str[i] != str[len - i - 1]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main() {
    char input[100];
    int n;
	printf("Construct PDA\n");
    do {
        printf("Enter the string to be checked: ");
        scanf("%s", input);

        if (isAccepted(input)) {
            printf("String is accepted.\n");
        } else {
            printf("String is not accepted.\n");
        }

        printf("Enter 1 to continue or 0 to exit: ");
        scanf("%d", &n);
    } while (n != 0);

    return 0;
}
