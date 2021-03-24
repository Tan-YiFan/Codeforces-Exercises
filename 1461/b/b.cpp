#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500 + 10;
int T;
typedef long long ll;
int n, m;
char c[N][N];
int l[N][N], r[N][N];
int mx[N][N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", c[i] + 1);
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (c[i][j - 1] == '*') {
                    l[i][j] = l[i][j - 1] + 1;
                } else {
                    l[i][j] = 0;
                }
            }
            for (int j = m; j; j--) {
                if (c[i][j + 1] == '*') {
                    r[i][j] = r[i][j + 1] + 1;
                } else {
                    r[i][j] = 0;
                }
            }
            for (int j = 1; j <= m; j++) {
                if (c[i][j] != '*') {
                    mx[i][j] = 0;
                } else {
                    mx[i][j] = 1 + min(l[i][j], min(r[i][j], mx[i - 1][j]));
                    ans += mx[i][j];
                }
            }
        }
    
        printf("%lld\n", ans);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // printf("%d%c", mx[i][j], j == m ? '\n' : ' ');
                c[i][j] = '.';
                l[i][j] = r[i][j] = mx[i][j] = 0;
            }
        }
    }
    return 0;
}