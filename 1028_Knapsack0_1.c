#include <stdio.h>
#include <stdlib.h>
int f[1001][8193] = {{0}}, w[1001], v[1001];
char b[1001][8193];
int T = 0, R[1001];

void printKnaspItem(int i, int W)
{
    if (i == 0 || W == 0)
        return;
    if (b[i][W] == '<')
    {
        printKnaspItem(i - 1, W - w[i]);
        ++T;
        R[T] = i;
    }
    else
        printKnaspItem(i - 1, W);
}

int main()
{
    int weight, number;
    int i, j;
    scanf ("%d%d", &number, &weight);

    for (i = 1; i <= number; ++i)
        scanf("%d", &w[i]);
    for (i = 1; i <= number; ++i)
        scanf("%d", &v[i]);


    for (i = 1; i <= number; ++i)
    {
        for (j = 1; j <= weight; ++j)
        {
            if (w[i] > j)
            {
                        f[i][j] = f[i - 1][j];
                        b[i][j] = '>';
            }
            else
            {
                    if (v[i] + f[i - 1][j - w[i]] > f[i - 1][j])
                    {
                        f[i][j] = v[i] + f[i - 1][j - w[i]];
                        b[i][j] = '<';
                    }
                    else
                    {
                        f[i][j] = f[i - 1][j];
                        b[i][j] = '>';
                    }
            }
        }
    }
    printKnaspItem(number, weight);

    printf("%d\n", T);

    for (i = 1; i < T; ++i)
        printf("%d ", R[i]);
    printf("%d", R[i]);

    return 0;
}
