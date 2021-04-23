#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100 + 10;
int T;
typedef long long ll;
mt19937 rn(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
int b[N][N];
int ans[N][N];
int ord[N];
int cur[N];
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> b[i][j];
			}
		}
		for (int j = 1; j <= m; j++) {
			cur[j] = ans[1][j] = b[1][j];
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				ord[j] = j;
			}
			sort(ord + 1, ord + m + 1, [](int u, int v) {return cur[u] > cur[v]; });
			sort(&(b[i][1]), &(b[i][m + 1]));
			for (int j = 1; j <= m; j++) {
				ans[i][ord[j]] = b[i][j];
				cur[ord[j]] = min(cur[ord[j]], b[i][j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				printf("%d%c", ans[i][j], j == m ? '\n' : ' ');
			}
		}
	}
	return 0;
}