#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n, m, k;
int a[N];
int c[N][101];
const int MOD = 1000000007;
void initial()
{
    c[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        c[i][1] = i;
        c[i][0] = 1;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= min(100, i); j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            c[i][j] %= MOD;
        }
    }
}
int main()
{
    initial();
    /* for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= min(i, 50); j++) {
            printf("%lld%c", c[i][j], j == min(i, 50) ? '\n' : ' ');
        }
    } */
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        sort(a + 1, a + n + 1);
        int last = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            while (last <= n && a[last] <= a[i] + k) {
                last++;
            }
            if (last - i < m - 1) {
                continue;
            }
            ans += c[last - i - 1][m - 1];
            ans %= MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}