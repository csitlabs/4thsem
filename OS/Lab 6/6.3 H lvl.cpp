// Hierarchial Directory Simulation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIRS 100
#define MAX_FILES 100
#define MAX_NAME_LENGTH 50

struct Directory {
    char name[MAX_NAME_LENGTH];
    struct Directory* subdirectories[MAX_DIRS];
    char files[MAX_FILES][MAX_NAME_LENGTH];
    int num_subdirectories;
    int num_files;
};

struct Directory* createDirectory(char name[]) {
    struct Directory* newDir = (struct Directory*)malloc(sizeof(struct Directory));
    if (newDir == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newDir->name, name);
    newDir->num_subdirectories = 0;
    newDir->num_files = 0;
    return newDir;
}

void freeMemory(struct Directory* dir) {
    if (dir == NULL) return;
    for (int i = 0; i < dir->num_subdirectories; ++i) {
        freeMemory(dir->subdirectories[i]);
    }
    free(dir);
}

void listDirectories(struct Directory* dir, int level) {
    printf("%*s%s\n", level * 4, "", dir->name);
    for (int i = 0; i < dir->num_subdirectories; ++i) {
        listDirectories(dir->subdirectories[i], level + 1);
    }

    for (int i = 0; i < dir->num_files; ++i) {
        printf("%*s- %s\n", (level + 1) * 4, "", dir->files[i]);
    }
}

int main() {
    struct Directory* root = createDirectory("Root");
    char choice[MAX_NAME_LENGTH];

    printf("Hierarchical Directory Simulation\n");
	printf("\n1. Create directory\n");
        printf("2. Add file to directory\n");
        printf("3. List directories and files\n");
        printf("4. Exit\n");
    while (1) {
        
        printf("Enter your choice: ");
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            char name[MAX_NAME_LENGTH];
            printf("Enter directory name: ");
            scanf("%s", name);

            struct Directory* currentDir = root;
            while (1) {
                printf("Enter the parent directory (or type 'root' to select root): ");
                scanf("%s", choice);
                if (strcmp(choice, "root") == 0) {
                    break;
                }
                int found = 0;
                for (int i = 0; i < currentDir->num_subdirectories; ++i) {
                    if (strcmp(currentDir->subdirectories[i]->name, choice) == 0) {
                        currentDir = currentDir->subdirectories[i];
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Directory not found. Try again.\n");
                }
            }

            if (currentDir->num_subdirectories < MAX_DIRS) {
                currentDir->subdirectories[currentDir->num_subdirectories++] = createDirectory(name);
                printf("Directory '%s' created.\n", name);
            } else {
                printf("Maximum number of directories reached in this level.\n");
            }
       } else if (strcmp(choice, "2") == 0) {
            char fileName[MAX_NAME_LENGTH];
            printf("Enter file name: ");
            scanf("%s", fileName);

            struct Directory* currentDir = root;
            while (1) {
                printf("Enter the directory to add the file (or type 'root' to select root): ");
                scanf("%s", choice);
                if (strcmp(choice, "root") == 0) {
                    break;
                }
                int found = 0;
                for (int i = 0; i < currentDir->num_subdirectories; ++i) {
                    if (strcmp(currentDir->subdirectories[i]->name, choice) == 0) {
                        currentDir = currentDir->subdirectories[i];
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Directory not found. Try again.\n");
                }
            }

            // Check if the file with the same name already exists
            int fileExists = 0;
            for (int i = 0; i < currentDir->num_files; ++i) {
                if (strcmp(currentDir->files[i], fileName) == 0) {
                    fileExists = 1;
                    break;
                }
            }

            if (!fileExists) {
                if (currentDir->num_files < MAX_FILES) {
                    strcpy(currentDir->files[currentDir->num_files++], fileName);
                    printf("File '%s' added to directory.\n", fileName);
                } else {
                    printf("Maximum number of files reached in this directory.\n");
                }
            } else {
                printf("A file with the same name already exists in this directory.\n");
            }
       } else if (strcmp(choice, "3") == 0) {
            printf("Directory structure:\n");
            listDirectories(root, 0);
        } else if (strcmp(choice, "4") == 0) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }


   freeMemory(root);

    return 0;
}

