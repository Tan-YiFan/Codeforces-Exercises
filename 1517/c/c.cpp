#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500 + 10;
int T;
typedef long long ll;
mt19937 rn(chrono::steady_clock::now().time_since_epoch().count());
int n;
int p[N];
int ans[N][N];
int num[N];
int loc[N];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		ans[i][i] = p[i];
		num[i] = i - 1;
		loc[p[i]] = i;
	}
	bool ok = true;
	int x = loc[1], y = loc[1];
	for (int k = 1; k < n; k++) {
		int x_nxt, y_nxt;
		int side = n - k;
		for (int j = 1; j <= side; j++) {
			int i = n - side + j;
			if (j < y) {
				ans[i][j] = ans[i - 1][j];
			} else {
				ans[i][j] = ans[i][j + 1];
			}
			if (ans[i][j] == k + 1) {
				x_nxt = i, y_nxt = j;
			}
		}
		x = x_nxt, y = y_nxt;
	}
	if (!ok) {
		puts("-1");
	} else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				printf("%d%c", ans[i][j], j == i ? '\n' : ' ');
			}
		}
	}
	return 0;
}