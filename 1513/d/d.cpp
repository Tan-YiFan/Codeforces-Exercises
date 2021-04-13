#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n, p;
int b[N];
pair<int, int> a[N];
bool edge[N];

/* reference */
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		scanf("%d %d", &n, &p);
		for (int i = 1; i <= n; i++) {
			scanf("%d", b + i);
			a[i].first = b[i];
			a[i].second = i;
			edge[i] = false;
		}
		sort(a + 1, a + n + 1);
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			int cur = a[i].first;
			if (cur >= p) {
				break;
			}
			for (int j = a[i].second; j > 1; j--) {
				if (edge[j - 1]) {
					break;
				}
				if (b[j - 1] % cur == 0) {
					edge[j - 1] = true;
					ans += cur;
				} else break;
			}
			for (int j = a[i].second; j < n; j++) {
				if (edge[j]) {
					break;
				}
				if (b[j + 1] % cur == 0) {
					edge[j] = true;
					ans += cur;
				} else break;
			}
		}
		for (int i = 1; i < n; i++) {
			if (!edge[i]) {
				ans += p;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}