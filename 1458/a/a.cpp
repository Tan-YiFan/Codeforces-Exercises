#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n, m;
ll a[N], b[N], ans[N];
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld", b + i);
    }
    sort(a + 1, a + n + 1);
    ll gcd_a = (a[2] - a[1]);
    for (int i = 3; i <= n; i++) {
        gcd_a = __gcd(gcd_a, a[i] - a[i - 1]);
    }
    // printf("%lld\n", gcd_a);
    for (int i = 1; i <= m; i++) {
        printf("%lld%c", n == 1 ? (b[i] + a[1]) : __gcd(gcd_a, b[i] + a[1]), i == m ? '\n' : ' ');
    }
    return 0;
}