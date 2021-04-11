#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
const int MOD = 1e9 + 7;
int T;
typedef long long ll;
int n;
int a[N];
int bits[N][32];
bool side[N];
ll fact[N];
bool initial()
{
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i <= 200000; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}
}
int main()
{
	initial();
	for (scanf("%d", &T); T; T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
		}
		for (int i = 1; i <= n; i++) {
			side[i] = true;
			int temp = a[i];
			for (int j = 0; j < 32; j++) {
				if (temp & 1) {
					bits[i][j] = 1;
				} else {
					bits[i][j] = 0;
				}
				temp >>= 1;
			}
		}
		// bool ok = true;
		for (int j = 0; j < 32; j++) {
			int zero = 0;
			for (int i = 1; i <= n; i++) {
				if (bits[i][j] == 0) {
					zero++;
				}
			}
			if (zero == 0 || zero == n) {
				continue;
			}
			for (int i = 1; i <= n; i++) {
				if (bits[i][j] == 1) {
					side[i] = false;
				}
			}
		}
		ll cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (side[i]) {
				cnt++;
			}
		}
		cnt = (cnt * (cnt - 1)) % MOD;
		printf("%lld\n", ((fact[n - 2] * cnt) % MOD));
	}
	return 0;
}