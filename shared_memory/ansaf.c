// user1.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define name "/new_name"

typedef struct {
    char msg[100];
    int chance;
    int exit;
    int var;
} share;

int main() {
    share *ptr;
    int fd;
    fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(share));
    ptr = mmap(0, sizeof(share), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    ptr->exit = 0;
    ptr->var = 0;
    ptr->chance = 0;
    while(ptr->exit != 1) {
        while(ptr->chance == 1) {
            printf("message from asma: %s", ptr->msg);
            if (!strcmp(ptr->msg, "stop")) {
                //printf("hii");
                ptr->exit = 1;
                break;
            }
            ptr->chance = 0;
        }
        printf("\nansaf: ");
        scanf("%s", ptr->msg);
        ptr->var = 1;
        while(ptr->var == 1);

        
    }
    printf("exited ansaf\n");
     munmap(ptr,sizeof(share));
     shm_unlink(name);
    return 0;
}
