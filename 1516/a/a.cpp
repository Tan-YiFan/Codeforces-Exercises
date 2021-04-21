#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
mt19937 rn(chrono::steady_clock::now().time_since_epoch().count());
int n, k;
int a[N];
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i < n; i++) {
			if (k < a[i]) {
				a[i] -= k;
				a[n] += k;
				break;
			} else {
				a[n] += a[i];
				k -= a[i];
				a[i] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			printf("%d%c", a[i], i == n ? '\n' : ' ');
		}
	}
	return 0;
}