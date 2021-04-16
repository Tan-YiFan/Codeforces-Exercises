#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
ll a[N], b[N];
ll floor(ll x, ll y)
{
	return (x + y - 1) / y;
}
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		ll n, c;
		scanf("%lld %lld", &n, &c);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", a + i);
		}
		for (int i = 1; i < n; i++) {
			scanf("%lld", b + i);
		}
		ll ans = floor(c, a[1]);
		ll last = 0;
		ll remaining = 0;
		for (int i = 1; i < n; i++) {
			if (c - remaining < 0ll) {
				break;
			}
			last += 1 + floor(max(0ll, b[i] - remaining), a[i]);
			remaining = remaining - b[i] + a[i] * floor(max(0ll, b[i] - remaining), a[i]);
			// c -= remaining;
			ll temp = floor(max(0ll, c - remaining), a[i + 1]);
			ans = min(ans, last + temp);
		}
		printf("%lld\n", ans);
	}
	return 0;
}