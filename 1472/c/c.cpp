#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n;
int a[N];
ll score[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        for (int i = n; i; i--) {
            if (i + a[i] > n) {
                score[i] = a[i];
            } else {
                score[i] = a[i] + score[i + a[i]];
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, score[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}