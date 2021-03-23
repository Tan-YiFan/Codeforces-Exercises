#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n;
int c[N];
ll a[N], min_a[N], sum_a[N];
ll b[N], min_b[N], sum_b[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", c + i);
            if (i & 1) {
                a[(i + 1) >> 1] = c[i];
            } else {
                b[i >> 1] = c[i];
            }
        }
        min_a[1] = sum_a[1] = a[1];
        min_b[1] = sum_b[1] = b[1];
        
        int a_len = (n + 1) >> 1;
        int b_len = n >> 1;
        for (int i = 2; i <= a_len; i++) {
            min_a[i] = min(min_a[i - 1], a[i]);
            sum_a[i] = sum_a[i - 1] + a[i];
        }
        for (int i = 2; i <= b_len; i++) {
            min_b[i] = min(min_b[i - 1], b[i]);
            sum_b[i] = sum_b[i - 1] + b[i];
        }
        ll ans = 1ll << 60;

        for (int i = 2; i <= n; i++) {
            int path_a = (i + 1) >> 1;
            int path_b = i >> 1;
            ll cost_a = min_a[path_a] * (n - path_a) + sum_a[path_a];
            ll cost_b = min_b[path_b] * (n - path_b) + sum_b[path_b];
            ll cnt = cost_a + cost_b;
            ans = min(ans, cnt);
        }

        printf("%lld\n", ans);
    }
    return 0;
}