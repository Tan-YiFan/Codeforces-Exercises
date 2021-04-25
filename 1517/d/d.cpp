#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500 + 10;
const long long INF = 1e15;
int T;
typedef long long ll;
mt19937 rn(chrono::steady_clock::now().time_since_epoch().count());
ll ans[N][N][11];
int n, m, k;
ll east[N][N], south[N][N];
inline ll min_of4(ll a, ll b, ll c, ll d)
{
	return min(a, min(b, min(c, d)));
}
inline ll min_of5(ll a, ll b, ll c, ll d, ll e)
{
	return min(a, min(b, min(c, min(d, e))));
}
int main()
{
	memset(ans, 0, sizeof(ans));
	// cin >> n >> m >> k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		east[i][0] = INF;
		for (int j = 1; j < m; j++) {
			// cin >> east[i][j];
			scanf("%lld", &(east[i][j]));
			// east[i][j] = 1e6;
		}
		east[i][m] = INF;
	}
	// for (int j = 1; j <= m; j++) {
	// 	south[0][j] = INF;
	// 	for (int i = 1; i < n; i++) {
	// 		// cin >> south[i][j];
	// 		south[i][j] = uniform_int_distribution<ll>(1, 1000000)(rn);
	// 	}
	// 	south[n][j] = INF;
	// }
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			south[i][j] = INF;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			// cin >> south[i][j];
			scanf("%lld", &(south[i][j]));
		}
	}
	if (k & 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				printf("%d%c", -1, j == m ? '\n' : ' ');
			}
		}
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans[i][j][1] = 2 * min_of4(east[i][j], east[i][j - 1], south[i][j], south[i - 1][j]);
		}
	}
	k >>= 1;
	for (int z = 1; z <= k; z++) {
		for (int i = 0; i <= n + 1; i++) {
			ans[i][0][z] = ans[i][m + 1][z] = INF;
		}
		for (int j = 0; j <= m + 1; j++) {
			ans[0][j][z] = ans[n + 1][j][z] = INF;
		}
	}
	for (int z = 2; z <= k; z++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				ans[i][j][z] = INF;
				for (int y = 1; y < z; y++) {
					ans[i][j][z] = min(ans[i][j][z], ans[i][j][y] + ans[i][j][z - y]);
				}
				ans[i][j][z] = min_of5(ans[i][j][z],
					ans[i][j + 1][z - 1] + east[i][j] * 2,
					ans[i][j - 1][z - 1] + east[i][j - 1] * 2,
					ans[i + 1][j][z - 1] + south[i][j] * 2,
					ans[i - 1][j][z - 1] + south[i - 1][j] * 2);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%lld%c", ans[i][j][k], j == m ? '\n' : ' ');
		}
	}
	return 0;
}