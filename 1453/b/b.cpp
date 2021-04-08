#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n;
ll a[N];
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", a + i);
		}
		ll mx = max(abs(a[2] - a[1]), abs(a[n] - a[n - 1]));
		for (int i = 2; i < n; i++) {
			if ((a[i] <= a[i + 1]) != (a[i] >= a[i - 1])) {
				mx = max(mx, (min(abs(a[i + 1] - a[i]), abs(a[i] - a[i - 1]))) << 1);
			}
		}
		ll ans = 0;
		for (int i = 1; i < n; i++) {
			ans += abs(a[i] - a[i + 1]);
		}
		printf("%lld\n", ans - mx);
	}
	return 0;
}