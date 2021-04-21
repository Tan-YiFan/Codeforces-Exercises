#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
mt19937 rn(chrono::steady_clock::now().time_since_epoch().count());
int n;
int a[N];
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		cin >> n;
		int k = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			k ^= a[i];
		}
		int l = 0;
		bool ok = false;
		if (k == 0) {
			ok = true;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			l ^= a[i];
			if (l == k) {
				cnt++;
				l = 0;
			}
		}
		if (cnt >= 2) {
			ok = true;
		}
		
		if (ok) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}