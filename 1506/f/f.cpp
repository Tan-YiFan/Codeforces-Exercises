#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n;
int r[N];
int c[N];
int ord[N];
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", r + i);
			ord[i] = i;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", c + i);
		}
		ll ans = 0;
		/* printf("n:%d\n", n);
		for (int i = 1; i <= n; i++) {
			printf("r[%d]:%d, c[%d]:%d\n", i, r[i], i, c[i]);
		} */
		sort(ord + 1, ord + n + 1, [](int u, int v) {return r[u] < r[v]; });
		c[0] = 1, r[0] = 1;
		for (int i = 1; i <= n; i++) {
			int steps = r[ord[i]] - r[ord[i - 1]];
			if (steps == 0) {
				continue;
			}
			int le = (r[ord[i]] - c[ord[i]]) - (r[ord[i - 1]] - c[ord[i - 1]]);
			int ri = steps - le;
			if ((r[ord[i - 1]] + c[ord[i - 1]]) & 1) { // odd point
				ans += (le + 1) >> 1;
			} else {
				if (le == 0) {
					ans += ri;
				} else {
					le--;
					// ans++;
					ans += (le + 1) >> 1;
				}
			}
			// printf("ans: %lld\n", ans);
		}
		printf("%lld\n", ans);
		for (int i = 1; i <= n; i++) {
			r[i] = c[i] = 0;
		}
	}
	return 0;
}