#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the number of processes");
    scanf("%d", &n);
    int b[n], w[n], t[n], p[n];
    float tt, tw = 0.0;
    printf("Enter the busrt time of each processes");
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    printf("Enter the priority of each processes");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
                int temp2 = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp2;
            }
        }
    }

    printf("\n");

    w[0] = 0;
    t[0] = b[0];
    tt = t[0];
    for (int i = 1; i < n; i++)
    {
        w[i] = w[i - 1] + b[i - 1];
        t[i] = t[i - 1] + b[i];
        tt += t[i];
        tw += w[i];
    }
    printf("0");
    for (int i = 0; i < n; i++)
    {

        printf(" p%d  ", i + 1);
        printf("%d  ", t[i]);
    }

    printf(" \n The avaerage waiting time is %f", tw / n);
    printf(" \n The average turnaround time is %f", tt / n);
}