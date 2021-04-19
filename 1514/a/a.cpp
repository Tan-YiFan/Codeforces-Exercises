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
		cin >> n;
		bool ok = false;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			int j = sqrt(a[i]);
			if (j * j != a[i]) {
				ok = true;
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