/*write a program which opens the directory in which it is executed,
read a file contained in it
and display the status of each file contained in it*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    DIR *d;
    int exist;
    struct stat f1;
    struct dirent *dir_entry;

    d = opendir(".");
    if (d == NULL) {
        printf("could not open current directory");
        exit(EXIT_FAILURE);
    } else {
        for (dir_entry = readdir(d); dir_entry != NULL; dir_entry = readdir(d)) {
            exist = stat(dir_entry->d_name, &f1);
            if (exist < 0) {
                perror("Error getting file status");
                continue;
            }

            // Display file status
            printf("File: %s\n", dir_entry->d_name);
            printf("Size: %ld bytes\n", f1.st_size);
            printf("Owner UID: %d\n", f1.st_uid);
            printf("Group GID: %d\n", f1.st_gid);
            printf("---------------------------------\n");
        }
    }

    // Close the directory
    closedir(d);

    return 0;
}
