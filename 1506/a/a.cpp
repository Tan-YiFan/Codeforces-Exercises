#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
ll n, m, x;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%lld %lld %lld", &n, &m, &x);
        ll col = x % n;
        if (!col) col += n;
        ll row = (x + n - 1) / n;
        printf("%lld\n", (col - 1) * m + row);
    }
    return 0;
}