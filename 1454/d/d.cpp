#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
ll n;
int num[N];

int main()
{
	for (scanf("%d", &T); T; T--)
	{
		int len = 0;
		scanf("%lld", &n);
		int hi = sqrt(n) + 1;
		ll temp = n;
		for (int i = 2; i <= hi; i++) {
			while (temp % i == 0) {
				num[i]++;
				temp /= i;
			}
		}
		int mx = 0;
		for (int i = 2; i <= hi; i++) {
			if (num[mx] < num[i]) {
				mx = i;
			}
		}
		if (mx == 0) {
			printf("1\n%lld\n", n);
		} else {
			printf("%d\n", num[mx]);
			for (int i = 1; i < num[mx]; i++) {
				printf("%d ", mx);
				n /= mx;
			}
			printf("%lld\n", n);
		}
		for (int i = 2; i <= hi; i++) {
			num[i] = 0;
		}
	}
	return 0;
}