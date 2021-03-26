#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n;
int main()
{
    scanf("%d", &n);
    ll ans = 0;
    if (n & 1) {
        ans = 2 * (n / 2 + 1) * (n / 2 + 2);
    } else {
        ans = (n / 2 + 1) * (n / 2 + 1);
    }
    printf("%lld\n", ans);
    return 0;
}