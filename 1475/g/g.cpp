#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n;
int a[N];
int len;
int cnt[N];
int dp[N];
int dpmax[N];
// with reference
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        len = 0;
        // int mx = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            // mx = max(a[i], mx);
        }
        // sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            cnt[a[i]]++;
        }
        for (int i = 1; i <= 200000; i++) {
            dp[i] = cnt[i] + dpmax[i];
            for (int j = i << 1; j <= 200000; j += i) {
                dpmax[j] = max(dpmax[j], dp[i]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (ans < dp[a[i]]) {
                ans = dp[a[i]];
            } 
        }
        printf("%d\n", n - ans);
        memset(cnt, 0, sizeof(cnt));
        // memset(dp, 0, sizeof(dp));
        memset(dpmax, 0, sizeof(dpmax));
    }
    return 0;
}