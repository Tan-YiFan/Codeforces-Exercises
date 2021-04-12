#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
const int MOD = 998244353;
int T;
typedef long long ll;
int n, m;
char t[N];
char *s[N];
ll w[N];

int w1[N], w2[N], w3[N], w4[N];
int *l[N];
int *r[N];
int *u[N];
int *d[N];

ll mul[N];
// mul[1] = 1;
// mul[2] = 2 + 1;
// mul[3] = 4 + 1;
// mul[4] = 8 + 2 + 1;
void initial()
{
	w[0] = 1;
	for (int i = 1; i <= N; i++) {
		w[i] = w[i - 1] << 1;
		w[i] %= MOD;
	}
	mul[0] = 1;
	mul[1] = 1;
	for (int i = 2; i <= N; i++) {
		mul[i] = mul[i - 2] + w[i - 1];
		mul[i] %= MOD;
	}
}
int main()
{
	initial();
	scanf("%d %d", &n, &m);
	s[0] = t;
	l[0] = w1;
	r[0] = w2;
	u[0] = w3;
	d[0] = w4;
	for (int i = 1; i < n; i++) {
		s[i] = (char *)(s[i - 1]) + m;
		l[i] = (int *)(l[i - 1]) + m;
		r[i] = (int *)(r[i - 1]) + m;
		u[i] = (int *)(u[i - 1]) + m;
		d[i] = (int *)(d[i - 1]) + m;
	}
	int num = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'o') {
				num++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (s[i][j - 1] == 'o') {
				l[i][j] = l[i][j - 1] + 1;
			} else {
				l[i][j] = 0;
			}
		}
		for (int j = m - 2; j > 0; j--) {
			if (s[i][j + 1] == 'o') {
				r[i][j] = r[i][j + 1] + 1;
			} else {
				r[i][j] = 0;
			}
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 1; i < n; i++) {
			if (s[i - 1][j] == 'o') {
				u[i][j] = u[i - 1][j] + 1;
			} else {
				u[i][j] = 0;
			}
		}
		for (int i = n - 2; i > 0; i--) {
			if (s[i + 1][j] == 'o') {
				d[i][j] = d[i + 1][j] + 1;
			} else {
				d[i][j] = 0;
			}
		}
	}
	ll ans = 0;
	if (num <= 1) {
		puts("0");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (s[i][j] == 'o' && s[i][j + 1] == 'o') {
				// ans += w[num - 2];
				int temp = num - 2 - l[i][j];
				
				if (temp >= 0) {
					ll temp1 = w[temp] * mul[l[i][j]];
					
					ans += temp1;
				}
				ans %= MOD;
			}
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (s[i][j] == 'o' && s[i + 1][j] == 'o') {
				// ans += w[num - 2];
				int temp = num - 2 - u[i][j];

				if (temp >= 0) {
					ll temp1 = w[temp] * mul[u[i][j]];
					ans += temp1;
				}
				ans %= MOD;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}