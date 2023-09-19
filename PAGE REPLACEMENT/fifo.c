#include <stdio.h>
int main()
{
    int n, f, pf = 0, ph = 0;
    printf("Enter the length of the reference string");
    scanf("%d", &n);
    printf("Enter the length of the  frame size");
    scanf("%d", &f);
    printf("Enter the reference string");
    int rf[n], fr[f];
    for (int i = 0; i < n; i++)
        scanf("%d", &rf[i]);
    for (int i = 0; i < f; i++)
        fr[i] = -1;
    int loc = 0;
    for (int i = 0; i < n; i++)
    {
        int fl = 0;
        for (int j = 0; j < f; j++)
        {
            if (rf[i] == fr[j])
            {
                fl = 1;
                break;
            }
        }
        if (fl == 0)
        {
            pf++;
            fr[loc] = rf[i];
            printf(" \n Page fault %d \n", pf);
            for (int k = 0; k < f; k++)
                printf("  %d", fr[k]);
            loc++;
        }
        else
        {
            ph++;
            printf("\n page hit %d \n ", ph);
            for (int k = 0; k < f; k++)
                printf("  %d", fr[k]);
        }
        if (loc == f)
            loc = 0;
    }
}