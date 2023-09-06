#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, count = 0, ct = 0, q;
    printf("Enter the number of processes");
    scanf("%d", &n);
    int b[n], w[n], t[n], r[n], f[n];
    float tt, tw = 0.0;
    printf("Enter the busrt time of each processes");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        r[i] = b[i];
        f[i] = 0;
    }
    printf("Enter the time quantum");
    scanf("%d", &q);
    int i = 0;
    while (count != n)
    {
        if (f[i] == 0)
        {

            if (r[i] <= q)
            {
                ct += r[i];
                count++;
                r[i] = 0;
                t[i] = ct;
                f[i] = 1;
            }
            else
            {
                ct = ct + q;
                r[i] -= q;
            }

            i++;
        }
        else
            i++;

        if (i == n)
            i = 0;
    }

    for (i = 0; i < n; i++)
    {
        w[i] = t[i] - b[i];
        tw += w[i];
        tt += t[i];
    }
    printf(" \n The avaerage waiting time is %f", tw / n);
    printf(" \n The average turnaround time is %f", tt / n);
}