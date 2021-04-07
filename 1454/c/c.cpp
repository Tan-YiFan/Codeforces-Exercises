#include <bits/stdc++.h>
using namespace std;

constexpr int N = 400000 + 10;
int T;
typedef long long ll;
int n;
int a[N];
int l[N];
int ans[N];
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			// a[n + i] = a[i];
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] != a[n]) {
				ans[a[i]] = 1;
			} else {
				ans[a[i]] = 0;
			}
		}
		int len = 0;
		for (int i = 2; i <= n; i++) {
			if (a[i - 1] != a[i]) {
				ans[a[i]]++;
			}
		}
		int o = n;
		for (int i = 1; i <= n; i++) {
			o = min(o, ans[a[i]]);
		}
		printf("%d\n", o);
	}
	return 0;
}