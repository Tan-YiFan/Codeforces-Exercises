#include <bits/stdc++.h>
using namespace std;

constexpr int N = 600000 + 10;
int T;
typedef long long ll;
int n, m;
int k[N], c[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", k + i);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", c + i);
        }
        for (int i = 1; i <= n; i++) {
            c[m + i] = c[k[i]];
        }
        sort(c + 1, c + m + n + 1);
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += c[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}