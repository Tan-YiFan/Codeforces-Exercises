#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n, k;
ll h[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", h + i);
        }
        bool ans = true;
        ll lo = h[1], hi = h[1];
        for (int i = 2; i <= n; i++) {
            lo = max(h[i], lo - k + 1);
            hi = min(hi + k - 1, h[i] + k - 1);
            if (lo > hi) {
                ans = false;
                break;
            } 
        }
        if (lo > h[n] || hi < h[n]) {
            ans = false;
        } 
        if (ans) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}