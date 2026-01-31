#include <stdio.h>

int main() {
    FILE *file;
    char buffer[100];

    // Open file in write+read mode. Creates file if it does not exist
    file = fopen("data.txt", "w+");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Write data to file
    fprintf(file, "Hello, File Handling in C!");

    // Move file pointer to beginning
    fseek(file, 0, SEEK_SET);

    // Read data from file
    fgets(buffer, sizeof(buffer), file);

    // Print data to console
    printf("Data read from file: %s\n", buffer);

    // Close file
    fclose(file);

    return 0;
}