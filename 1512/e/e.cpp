#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500 + 10;
int T;
typedef long long ll;

bool b[N];
int pref[N], suff[N];
void solve(int n, int k, int s)
{
	if (!s || !k || !n) {
		return;
	}
	if (s - n >= pref[k - 1]) {		
		b[n] = true;
		solve(n - 1, k - 1, s - n);
	} else {
		solve(n - 1, k, s);
	}
}
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		memset(b, 0, sizeof(b));
		int n, l, r, s;
		scanf("%d %d %d %d", &n, &l, &r, &s);
		int mn = 0, mx = 0;
		pref[0] = 0;
		for (int i = 1; i <= n; i++) {
			pref[i] = pref[i - 1] + i;
		}
		suff[n + 1] = 0;
		for (int i = n; i; i--) {
			suff[i] = suff[i + 1] + i;
		}
		if (s < pref[r - l + 1] || s > suff[n - (r - l + 1) + 1]) {
			puts("-1");
			continue;
		}
		solve(n, r - l + 1, s);
		stack<int> ans1, ans2;
		for (int i = 1; i <= n; i++) {
			if (b[i]) {
				ans1.push(i);
			} else {
				ans2.push(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (l <= i && i <= r) {
				printf("%d", ans1.top());
				ans1.pop();
			} else {
				printf("%d", ans2.top());
				ans2.pop();
			}
			putchar(i == n ? '\n' : ' ');
		}
	}
	return 0;
}