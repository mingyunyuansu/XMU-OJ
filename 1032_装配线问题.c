#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, f1[1001], f2[1001],e1, e2, x1, x2, a1[1001], a2[1001], t1[1000], t2[1000], i, f;
    scanf("%d", &n);
    scanf("%d%d%d%d", &e1, &e2, &x1, &x2);
    for (i = 1; i <= n; ++i)
        scanf("%d", &a1[i]);
    for (i = 1; i <= n; ++i)
        scanf("%d", &a2[i]);
    for (i = 1; i < n; ++i)
        scanf("%d", &t1[i]);
    for (i = 1; i < n; ++i)
        scanf("%d", &t2[i]);

    f1[1] = e1 + a1[1];
    f2[1] = e2 + a2[1];
    for (i = 2; i <= n; ++i)
    {
        f1[i] = (f1[i - 1] + a1[i] <= f2[i - 1] + t2[i - 1] + a1[i])? (f1[i - 1] + a1[i]) : (f2[i - 1] + t2[i - 1] + a1[i]);
        f2[i] = (f2[i - 1] + a2[i] <= f1[i - 1] + t1[i - 1] + a2[i])? (f2[i - 1] + a2[i]) : (f1[i - 1] + t1[i - 1] + a2[i]);
    }
    f = (f1[n] + x1 <= f2[n] + x2)? f1[n] + x1 : f2[n] + x2;

    printf("%d", f);
    return 0;
}
