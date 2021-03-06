#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n, x;
ll pref[N];
ll a[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        scanf("%d", &x);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", a + i);
            pref[i] = pref[i - 1] + a[i];
        }
        int min_index = 0;
        int min_time = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            int temp = 0;
            while (a[i] % x == 0) {
                a[i] /= x;
                temp++;
            }
            if (temp < min_time) {
                min_time = temp;
                min_index = i;
            } 
        }
        ll ans = (min_time + 1) * pref[n] + pref[min_index - 1];
        printf("%lld\n", ans);
    }
    return 0;
}