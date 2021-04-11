#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n, k;
int ans[N];

int main()
{
	for (scanf("%d", &T); T; T--)
	{
		scanf("%d %d", &n, &k);
		if (k > ((n - 1) >> 1)) {
			puts("-1");
		} else {
			for (int i = 1; i <= n; i++) {
				ans[i] = i;
			}
			for (int i = 1; i <= k; i++) {
				swap(ans[n - (i << 1) + 1], ans[n]);
			}
			for (int i = 1; i <= n; i++) {
				printf("%d%c", ans[i], i == n ? '\n' : ' ');
			}
		}
	}
	return 0;
}