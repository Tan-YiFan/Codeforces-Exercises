#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n, m;
int b[N], l[N];
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", b + i);
		}
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			scanf("%d", l + i);
			for (int j = 1; j <= n; j++) {
				if (b[j] == l[i]) {
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}