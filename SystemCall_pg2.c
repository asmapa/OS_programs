/*write a program where a parant process creates a 
child process and then the child process loads another program to add
2 numbers into its memory space .The parant process should wait for the child 
process to exit */

//for running 1.gcc mainFile.c -o mainFile  2.gcc add.c -o add 3) ./mainFile

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    int var;
    var=fork();
    if(var <0)
    {
        printf("error occured !!!!");
    }
    else if(var==0)
    {
        printf("child process started pid %d!!!",getpid());
        execl("./add","add",NULL);
        exit(0);
    }
    else
    {
        wait(NULL);
        printf("child process completed");
        exit(0);
    }
}