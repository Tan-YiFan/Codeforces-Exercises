#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n;
int a[N];
int ord[N];
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			ord[i] = i;
		}
		sort(ord + 1, ord + n + 1, [](int u, int v) {return a[u] < a[v]; });
		ord[n + 1] = 0;
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			if (a[ord[i]] != a[ord[i + 1]]) {
				ans = ord[i];
				break;
			} else {
				while (a[ord[i]] == a[ord[i + 1]]) {
					i++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}