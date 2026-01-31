#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    // List files in current directory
    printf("Listing files in current directory:\n");
    dir = opendir(".");

    if (dir == NULL) {
        perror("Unable to open directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);

    // Change directory to /tmp
    if (chdir("/tmp") != 0) {
        perror("Failed to change directory");
        return 1;
    }

    printf("\nChanged working directory to /tmp\n");

    // Create directory testdir with permission 755
    if (mkdir("testdir", 0755) == 0) {
        printf("Directory 'testdir' created successfully with permissions 755\n");
    } else {
        perror("Failed to create directory");
    }

    return 0;
}