/*write a program to create a file,write some data to it and then read from it
use open write read and close system calls*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 100

int main() {
    int fd; // File descriptor
    char buffer[BUFFER_SIZE];
    

    // Open the file in write-only mode, create if it doesn't exist, truncate it to zero length
    fd = open("example.txt", O_RDWR );

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Write data to the file
    write(fd, "Hello, World!\n", 14);
  
    // Close the file
    close(fd);

    // Open the file in read-only mode
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read data from the file
    read(fd, buffer, BUFFER_SIZE);
   
    // Close the file
    close(fd);

    // Print the data read from the file
    printf("Data read from file: %s\n", buffer);

    return 0;
}
