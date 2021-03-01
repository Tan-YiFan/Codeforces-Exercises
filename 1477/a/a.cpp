#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n;
ll k;
ll x[N];
// reference
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %lld", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", x + i);
        }
        stable_sort(x + 1, x + n + 1);
        ll g = 0;
        for (int i = 2; i <= n; i++) {
            g = __gcd(g, x[i] - x[1]);
        }
        if ((k - x[1]) % g) {
            puts("NO");
        } else {
            puts("YES");
        }
    }
    return 0;
}