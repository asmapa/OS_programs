#include <stdio.h>
#include <stdlib.h>

int requests[50], diff[10][10], seekseq[50], lowq[50], uppq[50], l, u, head, scount, n, h, dsize;
char dir;

void displaySeektimes(int req[], int count, int r)
{
    int i;
    printf("Seek Sequence \n%d -> ", h);
    for (i = 0; i < r; i++)
        printf("%d -> ", req[i]);
    printf("%d\n", req[i]);
    printf("Total seek time\n%d\n", count);
}

void fcfs()
{
    int i;
    head = h;
    scount = 0;
    int hi,hihi;
    printf("\nFCFS\n");
    int k;
    for (k = 0; k < n; k++)
    {
        scount += abs(requests[k] - head);
        head = requests[k];
    }
    displaySeektimes(requests, scount, n - 1);
}





void scan()
{
    int i, j, y, ss = 1;
    head = h;
    scount = 0;
    l = u = 0;
    seekseq[0] = head;

    printf("\nSCAN\n");

    if (dir == 'l')
        lowq[l++] = 0;
    else
        uppq[u++] = dsize - 1;

    for (i = 0; i < n; i++)
    {
        if (requests[i] < head)
            lowq[l++] = requests[i];
        else
            uppq[u++] = requests[i];
    }
      // Bubble sort for lowq array
    for (i = 0; i < l - 1; i++) {
        for (j = 0; j < l - i - 1; j++) {
            if (lowq[j] > lowq[j + 1]) {
                int temp = lowq[j];
                lowq[j] = lowq[j + 1];
                lowq[j + 1] = temp;
            }
        }
    }

    // Bubble sort for uppq array
    for (i = 0; i < u - 1; i++) {
        for (j = 0; j < u - i - 1; j++) {
            if (uppq[j] > uppq[j + 1]) {
                int temp = uppq[j];
                uppq[j] = uppq[j + 1];
                uppq[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < 2; i++)
    {
        if (dir == 'l')
        {
            for (j = ss, y = l - 1; y >= 0; y--, j++)
            {
                seekseq[j] = lowq[y];
                scount += abs(lowq[y] - head);
                head = lowq[y];
            }
            ss = j;
            dir = 'r';
        }
        else if (dir == 'r')
        {
            for (j = ss, y = 0; y < u; y++, j++)
            {
                seekseq[j] = uppq[y];
                scount += abs(uppq[y] - head);
                head = uppq[y];
            }
            ss = j;
            dir = 'l';
        }
    }

    displaySeektimes(seekseq, scount+2, ss - 1);
}

void cscan()
{
    int i, j, y, ss = 1;
    head = h;
    scount = 0;
    l = u = 0;
    seekseq[0] = head;

    printf("\nCSCAN\n");

    lowq[l++] = 0;
    uppq[u++] = dsize - 1;

    for (i = 0; i < n; i++)
    {
        if (requests[i] < head)
            lowq[l++] = requests[i];
        else
            uppq[u++] = requests[i];
    }
         // Bubble sort for lowq array
    for (i = 0; i < l - 1; i++) {
        for (j = 0; j < l - i - 1; j++) {
            if (lowq[j] > lowq[j + 1]) {
                int temp = lowq[j];
                lowq[j] = lowq[j + 1];
                lowq[j + 1] = temp;
            }
        }
    }

    // Bubble sort for uppq array
    for (i = 0; i < u - 1; i++) {
        for (j = 0; j < u - i - 1; j++) {
            if (uppq[j] > uppq[j + 1]) {
                int temp = uppq[j];
                uppq[j] = uppq[j + 1];
                uppq[j + 1] = temp;
            }
        }
    }

    if (dir == 'l')
    {
        for (j = ss, y = l - 1; y >= 0; y--, j++)
        {
            seekseq[j] = lowq[y];
            scount += abs(lowq[y] - head);
            head = lowq[y];
        }
        for (y = u - 1; y >= 0; y--, j++)
        {
            seekseq[j] = uppq[y];
            scount += abs(uppq[y] - head);
            head = uppq[y];
        }
        ss = j;
    }
    else if (dir == 'r')
    {
        for (j = ss, y = 0; y < u; y++, j++)
        {
            seekseq[j] = uppq[y];
            scount += abs(uppq[y] - head);
            head = uppq[y];
        }
        for (y = 0; y < l; y++, j++)
        {
            seekseq[j] = lowq[y];
            scount += abs(lowq[y] - head);
            head = lowq[y];
        }
        ss = j;
    }

    displaySeektimes(seekseq, scount+2, ss - 1);
}



void main()
{
    printf("Enter the no of requests\n");
    scanf("%d", &n);
    printf("Enter the request sequence\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &requests[i]);
    printf("Enter the head position and direction\n");
    scanf("%d %c", &h, &dir);
    printf("Enter the disk size\n");
    scanf("%d", &dsize);

    fcfs();
    scan();
    cscan();
    
}