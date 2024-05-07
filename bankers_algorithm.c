#include<stdio.h>

int main() {
    // Number of processes and resources
    int n, m;
    
    // Maximum number of each resource
    int max[10][10];
    
    // Currently allocated resources to processes
    int alloc[10][10];
    
    // Available resources
    int avail[10];
    
    // Need of each process
    int need[10][10];
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    
    printf("Enter the maximum resource matrix: \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    
    printf("Enter the allocated resource matrix: \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    
    printf("Enter the available resource vector: \n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }
    
    // Calculate the need matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
    // Check if the processes can be allocated resources
    int finish[10] = {0}; // Initialize all processes as unfinished
    
    int safeSeq[10];
    int work[10];
    for(int i = 0; i < m; i++) {
        work[i] = avail[i];
    }
    
    int count = 0;
    while(count < n) {
        int found = 0;
        for(int i = 0; i < n; i++) {
            if(!finish[i]) {
                int j;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > work[j]) {
                        break;
                    }
                }
                if(j == m) {
                    for(int k = 0; k < m; k++) {
                        work[k] += alloc[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(!found) {
            printf("System is not in safe state\n");
            return 0;
        }
    }
    
    printf("System is in safe state\n");
    printf("Safe sequence: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", safeSeq[i]);
    }
    printf("\n");
    
    return 0;
}
