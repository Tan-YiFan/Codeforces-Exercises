#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
constexpr int M = 10000;
int T;
typedef long long ll;
mt19937 rn(chrono::steady_clock::now().time_since_epoch().count());
int nxt[N];
int a[N];
int n, q;
vector<int> prime;
bool exist[N];
vector<int> fact[M];
int m[N];
int pref[N];
int dp[20][N];
void initial()
{
	exist[1] = true;
	for (int i = 2; i <= 100000; i++) {
		if (!exist[i]) {
			for (int j = i + i; j <= 100000; j += i) {
				exist[j] = true;
			}
			prime.push_back(i);
		}
	}
	// printf("%d\n", prime.size());
	for (int i = 0; i < prime.size(); i++) {
		m[prime[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		int j = 0;
		while (a[i] > 1) {
			if (!exist[a[i]]) {
				fact[m[a[i]]].push_back(i);
				break;
			}
			if (a[i] % prime[j] == 0) {
				fact[j].push_back(i);
				while (a[i] % prime[j] == 0) {
					a[i] /= prime[j];
				}
			}
			j++;
		}
	}
	fill(nxt + 1, nxt + n + 1, n + 1);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < (int)(fact[i].size()) - 1; j++) {
			nxt[fact[i][j]] = min(nxt[fact[i][j]], fact[i][j + 1]);
		}
	}
	for (int i = n - 1; i > 0; i--) {
		nxt[i] = min(nxt[i], nxt[i + 1]);
	}
	for (int j = 1; j <= n; j++) {
		dp[0][j] = nxt[j];
	}
	dp[0][n + 1] = n + 1;
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= n + 1; j++) {
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}
	/* 	pref[1] = 1;
	int l = 1;
	for (int i = 2; i <= n; i++) {
		if (nxt[l] > i) {
			pref[i] = pref[i - 1];
		} else {
			pref[i] = pref[i - 1] + 1;
			l = i;
		}
	} */
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d%c", nxt[i], i == n ? '\n' : ' ');
	// }
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d%c", pref[i], i == n ? '\n' : ' ');
	// }
}
int main()
{
	// initial();
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	initial();
	for (int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		// cout << pref[r] - pref[l] + 1 << endl;
		/* if (nxt[l] > r) {
			puts("1");
		} else {
			cout << 1 + pref[r] - pref[nxt[l] - 1] + (pref[nxt[l]] == pref[nxt[l] - 1] ? 1 : 0) << endl;
		} */
		int ans = 0;
		for (int i = 17; i >= 0; i--) {
			if (dp[i][l] <= r) {
				ans += 1 << i;
				l = dp[i][l];
			}
		}
		ans++;
		cout << ans << endl;
	}
	return 0;
}