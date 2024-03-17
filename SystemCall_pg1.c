/*write a program which create a child process and the 
parant process waits for the child process to exit 
after printing the process id of the child and parant process
(use fork,wait,hetpid,getppid,and exit)*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    int par_pro;
    par_pro=fork();

    if(par_pro < 0)
    {
        printf("error");
    }
    else if(par_pro == 0)
    {
        printf("parant process ID is %d and child process ID is %d",getpid(),getppid());
        printf("child process terminated !!!");
        exit(0);
    }
    else
    {
        int w=wait(NULL);
        printf("parant terminated !!!");
        printf("wait is %d",w);
        exit(2);
    }
}