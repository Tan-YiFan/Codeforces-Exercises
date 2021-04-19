#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10, M = 21;
const int MOD = 1e9 + 7;
int T;
typedef long long ll;
int n, k;
ll dp[N][M];
void initial()
{
	for (int i = 1; i <= 100000; i++) {
		dp[i][1] = i;
	}
	for (int j = 1; j <= 20; j++) {
		dp[1][j] = 1;
		dp[2][j] = 1 << j;
	}
	for (int i = 1; i <= 100000; i++) {
		for (int j = 2; j <= 20; j++) {
			dp[i][j] = dp[i][j - 1] * i;
			dp[i][j] %= MOD;
		}
	}
}
int main()
{
	initial();
	for (scanf("%d", &T); T; T--)
	{
		cin >> n >> k;
		cout << dp[n][k] << endl;
	}
	return 0;
}