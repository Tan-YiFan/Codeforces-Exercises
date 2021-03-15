#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n;
ll miner[N], diamond[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        n <<= 1;
        int miner_sz = 0, diamond_sz = 0;
        for (int i = 1; i <= n; i++) {
            ll x, y;
            scanf("%lld %lld", &x, &y);
            if (x == 0) {
                miner[++miner_sz] = abs(y);
            } else {
                diamond[++diamond_sz] = abs(x);
            }
        }
        double ans = 0;
        sort(miner + 1, miner + miner_sz + 1);
        sort(diamond + 1, diamond + diamond_sz + 1);
        for (int i = 1; i <= diamond_sz; i++) {
            ans += sqrt(miner[i] * miner[i] + diamond[i] * diamond[i]);
        }
        printf("%.15f\n", ans);
        // cout << ans << endl;
    }
    return 0;
}