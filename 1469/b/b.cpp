#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100 + 10;
int T;
typedef long long ll;
int n, m;
int r[N], b[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        int mx_r = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", r + i);
            r[i] += r[i - 1];
            mx_r = max(mx_r, r[i]);
        }
        scanf("%d", &m);
        int mx_b = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%d", b + i);
            b[i] += b[i - 1];
            mx_b = max(mx_b, b[i]);
        }

        printf("%d\n", mx_r + mx_b);
    }
    return 0;
}