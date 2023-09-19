#include <stdio.h>
int main()
{
    int n, m, loc, fl, min, pf = 0, ph = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the size of the frame: ");
    scanf("%d", &m);
    int f[m];
    int dis[m];
    int fl2[m];
    int t = 0;
    for (int i = 0; i < m; i++)
        f[i] = -1;
    for (int i = 0; i < n; i++)
    {
        fl = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i] == f[j])
            {
                fl = 1;
                break;
            }
        }
        if (fl == 0)
        {
            if (i < m)
            {
                f[t] = arr[i];
                t++;
                pf++;
                printf(" \n Page fault %d \n", pf);
                for (int k = 0; k < m; k++)
                    printf("  %d", f[k]);
            }
            else
            {
                for (int j = 0; j < m; j++)
                {
                    fl2[j] = 0;
                    for (int t = i; t >= 0; t--)
                    {
                        if (arr[t] == f[j])
                        {
                            dis[j] = t;
                            fl2[j] = 1;
                            break;
                        }
                    }
                }
                min = dis[0];
                loc = 0;
                if (fl2[0] == 0)
                {
                    loc = 0;
                }
                else
                {
                    for (int k = 1; k < m; k++)
                    {
                        if (fl2[k] == 0)
                        {
                            loc = k;
                            break;
                        }
                        else
                        {
                            if (dis[k] < min)
                            {
                                min = dis[k];
                                loc = k;
                            }
                        }
                    }
                }
                f[loc] = arr[i];
                pf++;
                printf(" \n Page fault %d \n", pf);
                for (int k = 0; k < m; k++)
                    printf("  %d", f[k]);
            }
        }
        else
            ph++;
        printf("\n page hit %d \n ", ph);
        for (int k = 0; k < m; k++)
            printf("  %d", f[k]);
    }
    printf(" Page fault %d", pf);
    printf(" Page hit %d", ph);
}
