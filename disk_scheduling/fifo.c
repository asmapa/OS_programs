#include <stdio.h>
#include <stdlib.h>

int myAbs(int n) {
    if (n < 0) {
        return -n;  // Return the negative of n to make it positive
    } else {
        return n;   // Return n as it is if it's already positive
    }
}
int main()
{
   int n,RQ[100],initial,totalHeadMovement=0;
   printf("Enter the number of requests: ");
   scanf("%d", &n);
   printf("Enter the requests sequence: ");
   for(int i=0;i<n;i++)
   {
    scanf("%d",&RQ[i]);
   }
   printf("Enter the initial Head position: ");
   scanf("%d",&initial);
   
   for(int i=0;i<n;i++)
   {
      totalHeadMovement += myAbs(RQ[i] - initial);
      initial = RQ[i];
   }

   printf("\nTotal Head Movements: %d",totalHeadMovement);
   return 0;
}