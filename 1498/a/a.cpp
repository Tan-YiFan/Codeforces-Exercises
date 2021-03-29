#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
ll n;
ll gcd_sum()
{
    ll temp = n, sum = 0;
    while (temp) {
        sum += temp % 10;
        temp /= 10;
    }
    return __gcd(sum, n);
}
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%lld\n", &n);
        while (gcd_sum() == 1) {
            n++;
        }
        printf("%lld\n", n);
    }
    return 0;
}