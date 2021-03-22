#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n;
int a[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        sort(a + 1, a + n + 1);
        ll ans = 0;
        ll last = 1;
        for (int i = 1; i <= n; i++) {
            while (last <= n && a[last] <= a[i] + 2) {
                last++;
            }
            if (last - i < 2) {
                continue;
            }
            ans += (last - i - 1) * (last - i - 2) / 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}