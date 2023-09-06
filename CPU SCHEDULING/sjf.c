#include <stdio.h>
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of processes");
    scanf("%d", &n);
    int b[n], w[n], t[n];
    float tt, tw = 0.0;
    printf("Enter the busrt time of each processes");
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                int temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }

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

    printf(" \n The avaerage waiting time is %f", tw / n);
    printf(" \n The average turnaround time is %f", tt / n);
}