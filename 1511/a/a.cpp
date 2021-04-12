#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n;
int r;
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &r);
			switch (r) {
			case 1:
				ans++;
				break;
			case 3:
				ans++;
				break;
			default:
				;
			}
			
		}
		printf("%d\n", ans);
	}
	return 0;
}