#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n, m;

int a[N], b[N];
double f[N];

int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            b[i] = a[i];
        }
        sort(b + 1, b + n + 1);
        int start = n;
        while (start >= 1) {
            if (a[start] != b[start]) {
                break;
            }
            start--;
        }
        for (int i = 1; i <= n; i++) {
            f[i] = 1.0;
        }
        for (int i = 1; i <= m; i++) {
            int d;
            float e;
            scanf("%d %f", &d, &e);
            f[d] *= (1.0 - e);
        }
        double ans = 1.0;
        if (start <= 1) {
            puts("1.000000");
        } else {
            for (int i = start; i <= n; i++) {
                ans = ans * f[i];
            }
            printf("%.06f\n", 1.0 - ans);
        }
    }
    return 0;
}