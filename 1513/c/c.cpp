#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
const int MOD = 1e9 + 7;
int T;
typedef long long ll;
char s[20];
int m;
int ans[10][N];
void initial()
{
	for (int i = 0; i < 10; i++) {
		ans[i][0] = 1;
	}
	for (int j = 1; j <= N; j++) {
		ans[9][j] = (ans[0][j - 1] + ans[1][j - 1]) % MOD;
		for (int i = 0; i < 9; i++) {
			ans[i][j] = ans[i + 1][j - 1];
		}
	}
}
int main()
{
	initial();
	for (scanf("%d", &T); T; T--)
	{
		scanf("%s", s);
		scanf("%d", &m);

		int n = strlen(s);
		ll out = 0;
		for (int i = 0; i < n; i++) {
			out = out + ans[s[i] - '0'][m];
			out %= MOD;
		}
		printf("%lld\n", out);
	}
	return 0;
}