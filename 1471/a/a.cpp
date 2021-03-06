#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n, x;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &n, &x);
        ll sum_min = 0, sum_max = 0;
        for (int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            sum_max += (a + x - 1) / x;
            sum_min += a;
        }
        // sum_min /= x;
        sum_min = (sum_min + x - 1) / x;
        printf("%lld %lld\n", sum_min, sum_max);
    }
    return 0;
}