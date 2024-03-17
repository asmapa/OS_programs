//This help to find FCFS SJF priority and Round Robin scheduling
//it calculates response time,completion time,turn around time(include average)and waiting time(avg also)

#include<stdio.h>
#include<stdlib.h>

int process[20],arrival[20],burst[20],waiting[20],turn[20],completed[20],response[20];
int n,i,j,k;
float avgtat,avgwt;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sort()
{
    int min;
    for(i=0;i<n-1;i++)
    {
        min=i;

        for(j=i+1;j<n;j++)
        {
            if(arrival[j]<arrival[min])
            {
                min=j;
            }
        }
        if(min != i)
        {
            swap(&arrival[i],&arrival[min]);
            swap(&process[i],&process[min]);
            swap(&process[i],&process[min]);
        }
    }
}

void display()
{
    printf("\n ---------------------------------------------------------------------------------------------------\n");
    printf("\n process    arrival time    burst time    response time    complete time    turn_around     waiting\n");
    for(i=0;i<n;i++)
    {
        printf("   P%i\t\t%i\t\t%i\t\t%i\t\t%i\t\t%i\t\t%i\n",process[i],arrival[i],burst[i],response[i],completed[i],turn[i],waiting[i]);
    }
    printf("\nAverage waiting time : %f \t",avgwt);
    printf("Average turn around time : %f",avgtat);
    printf("\n -----------------------------------------------------------------------------------------------------\n");
}

void FCFS()
{
    int current_time=0;
    avgtat=0,avgwt=0;

    for(i=0 ; i<n ; i++)
    {
        if(current_time >= arrival[i])
        {
            waiting[i]=current_time - arrival[i];
            response[i]=waiting[i];
            completed[i]=arrival[i]+burst[i]+waiting[i];
            turn[i]=waiting[i]+burst[i];
            current_time=current_time+burst[i];

            avgtat=avgtat+turn[i];
            avgwt=avgwt+waiting[i];
        }
        else
        {
            current_time++;
            i--;
        }
    }

    avgtat=avgtat/n;
    avgwt=avgwt/n;
}

void SJF()
{
    avgtat=0,avgwt=0;
    int temp,min,var;
    completed[0]=arrival[0] + burst[0];
    turn[0]=completed[0]-arrival[0];
    waiting[0]=turn[0]-burst[0];
    response[0]=waiting[0];

    for(i=1;i<n;i++)
    {
        temp=completed[i-1];
        min=burst[i];

        for(j=i;j<n;j++)
        {
            if(temp >= arrival[j] && min >= burst[j])
            {
                min=burst[j];
                var=j;
            }
        }
        completed[var]=temp + burst[var];
        turn[var]=completed[var]-arrival[var];
        waiting[var]=turn[var]-burst[var];
        response[var]=waiting[var];

        swap(&arrival[var], &arrival[i]);
        swap(&burst[var], &burst[i]);
        swap(&waiting[var], &waiting[i]);
        swap(&turn[var], &turn[i]);
        swap(&completed[var],&completed[i]);
        swap(&response[var],&response[i]);
        swap(&process[var], &process[i]);
    }
    for(int j=0;j<n;j++)
    {
        avgtat=avgtat+turn[j];
        avgwt=avgwt+waiting[j];
    }
    avgtat=avgtat/n;
    avgwt=avgwt/n;
}



int main()
{
    printf(".......SCHEDULING ALGORITHMS........\n");
    int choice;
    while(1)
    {
        printf("1.FCFS\n2.SJF\n3.priority\n4.round robin\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        printf("Enter the number of process:");
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            process[i]=i+1;
        }
        printf("Enter the ARRIVAL and BURST time:");
        for(i=0;i<n;i++)
        {
            scanf("%d",&arrival[i]);
            scanf("%d",&burst[i]);
        }
        switch(choice)
        {
            case 1:sort();
            FCFS();
            display();
            break;

            case 2:sort();
            SJF();
            display();
            break;


        }

    }
}
