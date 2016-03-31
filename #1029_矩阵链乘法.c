#include <stdio.h>
#include <stdlib.h>

#define INFINITY 999999999

int main()
{
    int c, i, j, m[201][201], N, k, tmp, p[202];

    scanf("%d", &N);
    for (i = 0; i <= N; ++i)
        scanf("%d", &p[i]);

    for (i = 1; i <= N; ++i)
        m[i][i] = 0;

    for (c = 2; c <= N; ++c)
    {
        for (i = 1; i <= N - c + 1; ++i)
        {
            j = i + c - 1;
            m[i][j] = INFINITY;
            for (k = i; k <= j - 1; ++k)
            {
                tmp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (tmp < m[i][j])
                    m[i][j] = tmp;
            }
        }
    }

    printf("%d", m[1][N]);
    return 0;
}
