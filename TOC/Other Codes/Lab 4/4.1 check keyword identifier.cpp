//4. WAP to check valid identifier or keywords of c language

#include <stdio.h>
#include <string.h>

// Function declaration for isIdentifier
int isIdentifier(char input[]);

int main() {
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"
    };

    int i, res;
    char input[10];
    char choice;
	printf("Check valid identifier or keywords of c language");
    do {
        printf("\n\nEnter a string: ");
        gets(input); // Note: gets() is deprecated, consider using fgets().

        // Check if input is a keyword
        for (i = 0; i < 32; i++) {
            if (strcmp(keywords[i], input) == 0) {
                printf("Keyword\n");
                break; // Exit the loop if it's a keyword
            }
        }

        // If it's not a keyword, check if it's a valid identifier
        if (i == 32) {
            res = isIdentifier(input);
            if (res == 1) {
                printf("Identifier\n");
            } else {
                printf("Invalid Identifier\n");
            }
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume the newline character
        getchar(); // Consume the newline character left in the buffer

    } while (choice == 'y' || choice == 'Y');

    return 0; // Return 0 to indicate successful execution.
}

// Function to check if the given string is a valid identifier
int isIdentifier(char input[]) {
    int i = 0, current_state = 0;
    char c;
    while (input[i] != '\0') {
        c = input[i];
        switch (current_state) {
            case 0:
                if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == '_'))
                    current_state = 1;
                else
                    current_state = 2;
                break;
            case 1:
                if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == '_') || (c >= '0' && c <= '9'))
                    current_state = 1;
                else
                    current_state = 2;
                break;
        }
        i++;
    }

    if (current_state == 2)
        return 0;
    else
        return 1;
}

