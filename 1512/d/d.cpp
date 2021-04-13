#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n;
int b[N];
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		scanf("%d", &n);
		ll sum = 0;
		for (int i = 1; i <= n + 2; i++) {
			scanf("%d", b + i);
			sum += b[i];
		}
		// printf("sum:%lld\n", sum);
		sort(b + 1, b + n + 3);
		bool ok = false;

		if (b[n + 1] == sum - b[n + 2] - b[n + 1]) {
			ok = true;
			for (int i = 1; i <= n; i++) {
				printf("%d%c", b[i], i == n ? '\n' : ' ');
			}
			continue;
		}
		for (int i = 1; i <= n + 1; i++) {
			if (b[n + 2] == sum - b[i] - b[n + 2]) {
				ok = true;
				for (int j = 1; j <= n + 1; j++) {
					if (i != j) {
						printf("%d%c", b[j], (j == n + 1 || (i == n + 1 && j == n) ? '\n' : ' '));
					}
				}
				break;
			}
		}
		if (!ok)
			puts("-1");
	}
	return 0;
}