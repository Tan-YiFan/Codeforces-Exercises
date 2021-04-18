#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n;
int h[N], b[N];
ll dp[N];
int st[N];
int len;
ll r[N];
bool ok[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	dp[1] = b[1];
	st[++len] = 1;
	ll mx = max(0ll, dp[1]);
	for (int i = 2; i <= n; i++) {
		int m = i;
		dp[i] = dp[i - 1] + b[i];
/* 		while (len > 0 && h[st[len]] > h[i]) {
			dp[i] = max(dp[i], b[i] + dp[st[len] - 1]);
			len--;
		}
		if (len) {
			dp[i] = max(dp[i], dp[st[len]]);
		} else {
			dp[i] = max(dp[i], mx + b[i]);
		}
		st[++len] = i;
		mx = max(mx, dp[i]); */
		while (len > 0 && h[st[len]] > h[i]) {
			len--;
			r[st[len]] = max(r[st[len]], r[st[len + 1]]);
		}
		if (!len) {
			dp[i] = max(dp[i], mx + b[i]);
		} else {
			dp[i] = max(dp[i], dp[st[len]]);
			if (ok[st[len]])
				dp[i] = max(dp[i], b[i] + r[st[len]]);
		}
/* 		for (int j = i - 1; j >= 0; j--) {
			dp[i] = max(dp[i], dp[j] + b[m]);
			if (h[j] < h[m]) {
				m = j;
			}
			if (st[len] == j) {
				dp[i] = max(dp[i], dp[j]);
				break;
			}
		} */
		st[++len] = i;
		mx = max(mx, dp[i]);
		r[i] = dp[i];
		r[st[len - 1]] = max(r[st[len - 1]], dp[i]);
		ok[st[len - 1]] = true;
	}
	cout << dp[n] << endl;
	return 0;
}