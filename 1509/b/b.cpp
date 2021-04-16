#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
char s[N];
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		int n;
		scanf("%d", &n);
		scanf("%s", s + 1);
		bool ok = true;
		int l_len = 0, r_len = 0;
		int t_cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == 'T') {
				t_cnt++;
			}
		}
		if ((t_cnt & 1) || (t_cnt / 2 * 3) != n) {
			ok = false;
		}
		vector<int> l(n), r(n);
		for (int i = 1; i <= n; i++) {
			if (s[i] == 'T') {
				if (l_len != t_cnt >> 1) {
					l[l_len] = i;
					l_len++;
				} else {
					r[r_len] = i;
					r_len++;
				}
			}
		}
		int r_times = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == 'M') {
				if (l[r_times] > i || r[r_times] < i) {
					ok = false;
					break;
				}
				r_times++;
			}
		}
		if (ok) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}