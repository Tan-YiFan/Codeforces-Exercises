#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
mt19937 rn(chrono::steady_clock::now().time_since_epoch().count());
ll n;
const ll MX = 1e18 + 1;
int main()
{
	
	for (scanf("%d", &T); T; T--)
	{
		cin >> n;
		if ((n % 2050ll) != 0) {
			puts("-1");
		} else {
			n /= 2050;
			ll ans = 0;
			while (n) {
				ans += n % 10;
				n /= 10;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}