#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of processes");
    scanf("%d", &n);
    int b[30], w[30], t[30];
    float tt, tw = 0.0;
    printf("Enter the busrt time of each processes");
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
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
    printf("The avaerage waiting time is %f", tw / n);
    printf("\n The average turnaround time is %f", tt / n);
}