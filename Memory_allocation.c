#include<stdio.h>

int block[10],process[10],memory,pro,i,j,alloc[10],fragment[10];

void firstfit(int b[10],int p[10],int pro,int mem)
{
    //int fragment[10];
    printf("FIRST FIT\n");
    for(i=0;i<pro;i++)
    {
        alloc[i]=-1;
    }
    for (int i = 0; i < pro; i++) {
        fragment[i] = -1;
    }
    for(i=0;i<pro;i++)
    {
        for(j=0;j<mem;j++)
        {
            if(b[j] >= p[i])
            {
                alloc[i]=j;
                //fragment[i]=b[j]-p[i];
                b[j]=b[j]-p[i];
                break;
            }
        }
    }

    
}

void bestfit(int b[10], int p[10], int pro, int mem) {
    printf("BEST FIT\n");
  //  int fragment[10], block_allocated[10], block_index[10];
    // Reset block_allocated array
    for (int i = 0; i < pro; i++) {
        alloc[i] = -1;
    }

    // Initialize fragment array
    for (int i = 0; i < pro; i++) {
        fragment[i] = -1;
    }

   

   
    // Best Fit algorithm implementation
    for (int i = 0; i < pro; i++) {
        int best = -1;
        for (int j = 0; j < mem; j++) {
            if (b[j] >= p[i]) {
                if (best == -1) {
                    best = j;
                } else if (b[best] > b[j]) {
                    best = j;
                }
            }
        }
        if (best != -1) {
            alloc[i] = best;
            
           // fragment[i] = b[best] - p[i];
            b[best] = b[best] - p[i];
            
        }
    }

   
}

void worstfit(int b[10],int p[10],int pro,int mem)
{
    printf("WORST FIT\n");
  //  int fragment[10], block_allocated[10], block_index[10]; // Declare arrays to store fragmentation details
    for(i=0;i<pro;i++)
    {
        alloc[i]=-1;
    }
    for(i=0;i<pro;i++)
    {
        int best=-1;
        for(int j=0;j<mem;j++)
        {
            if(b[j] >= p[i])
            {
                if(best==-1)
                {
                    best=j;
                }
                else if(b[best] < b[j])
                {
                    best=j;
                }
            }
        }
        if(best !=-1)
        {
            alloc[i]=best;
            //fragment[i] = b[best] - p[i]; // Calculate fragmentation for each process
            b[best]=b[best]-process[i];
        }
    }

    
}


void display(int block[10])
{
     printf("Process No\tProcess Size\tBlock No:\tFragment\n");
    for (int i = 0; i < pro; i++) {
        if (alloc[i] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, process[i], alloc[i] + 1,block[i]-process[i]);
        } else {
            printf("%d\t\t%d\t\t-1\t\t-1\t\t-1 (No suitable block)\n", i + 1, process[i]); // Print message when no suitable block is found
        }
    }

    printf("External Fragmentation:\n");
    for (i = 0; i < memory; i++) {
        int isUsed = 0;
        for (j = 0; j < pro; j++) {
            if (alloc[j] == i) {
                isUsed = 1;
                break;
            }
        }
        if (!isUsed) {
            printf("Block[%d]: %d\n", i + 1, block[i]);
        }
    }



}  


int main()
{
    int block1[10],block2[10];
    printf("enter the number of process:");
    scanf("%d",&pro);
    printf("Enter the process size:");
    for(i=0;i<pro;i++)
    {
        printf("process[%d]:",i+1);
        scanf("%d",&process[i]);
    }
    printf("enter the number of blocks:");
    scanf("%d",&memory);
    printf("Enter the block size:");
    
    for(i=0;i<memory;i++)
    {
        printf("Block[%d]:",i+1);
        scanf("%d",&block[i]);
        block1[i]=block[i];
        block2[i]=block[i];    
    }

    firstfit(block,process,pro,memory);
    display(block);
    bestfit(block1,process,pro,memory);
    display(block1);
    worstfit(block2,process,pro,memory);
    display(block2);
    
}