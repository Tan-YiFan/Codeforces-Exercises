#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n;
int a[N];
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
		}
		int same = 0;
		int ans = 0;
		if (a[1] == a[2]) {
			same = a[1];
			for (int i = 3; i <= n; i++) {
				if (a[i] != same) {
					ans = i;
				}
			}
		} else if (a[2] == a[3]) {
			ans = 1;
		} else {
			ans = 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}