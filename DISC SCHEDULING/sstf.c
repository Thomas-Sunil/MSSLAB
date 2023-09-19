#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    printf("Enter the size of the disc");
    int n;
    scanf("%d", &n);
    int a[n], seq[n + 1], df[n], min, loc;
    printf("Enter the string");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int k = 1;
    printf("Enter the current head");
    int c;
    scanf("%d", &c);
    int cp = c;
    seq[0] = c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            df[j] = abs(cp - a[j]);
        }

        min = df[0];
        loc = 0;
        for (int j = 1; j < n; j++)
        {
            if (min > df[j])
            {
                min = df[j];
                loc = j;
            }
        }

        seq[k] = a[loc];
        cp = a[loc];
        a[loc] = 999;
        printf("%d  ", seq[k]);
        k++;
    }
    int s;
    for (int i = 1; i < n + 1; i++)
    {
        s += abs(seq[i] - seq[i - 1]);
    }
    printf("\n The total disc movement is %d", s);
}