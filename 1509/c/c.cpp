#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2000 + 10;
int T;
typedef long long ll;
int s[N];
ll dp[N][N];
int n;
void solve()
{
	for (int i = n; i; i--) {
		for (int j = i + 1; j <= n; j++) {
			dp[i][j] = s[j] - s[i] + min(dp[i + 1][j], dp[i][j - 1]);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	sort(s + 1, s + n + 1);
	solve();
	cout << dp[1][n] << endl;
	return 0;
}