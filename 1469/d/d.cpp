#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n;
int ans[N][2];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        int cnt = 0;
        int lo, hi = n;
        while ((lo = ceil(sqrt(hi))) > 1 && lo < hi) {
            for (int i = lo + 1; i < hi; i++) {
                ans[++cnt][0] = i;
                ans[cnt][1] = i + 1;
            }
            ans[++cnt][0] = hi;
            ans[cnt][1] = lo;
            ans[++cnt][0] = hi;
            ans[cnt][1] = lo;
            hi = lo;
        }
        printf("%d\n", cnt);
        for (int i = 1; i <= cnt; i++) {
            printf("%d %d\n", ans[i][0], ans[i][1]);
        }
    }
    return 0;
}