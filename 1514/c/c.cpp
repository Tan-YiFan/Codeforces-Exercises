#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n;
bool ans[N];
bool isprime(int k)
{
	int l = sqrt(k);
	for (int i = 2; i <= l + 1; i++) {
		if ((k % i) == 0) {
			return false;
		}
	}
	return true;
}
int ex_gcd(int a, int b, int &x, int &y)
{
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int r = ex_gcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
	return r;
}
int mod_reverse(int a, int n)
{
	int d, x, y;
	d = ex_gcd(a, n, x, y);
	if (d == 1) {
		return (x % n + n) % n;
	} else {
		return -1;
	}
}
// int main()
// {
// 	cin >> n;
// 	if (n == 2) {
// 		printf("1\n1\n");
// 		return 0;
// 	}
// 	int cnt = 1;
// 	ans[1] = true;
// 	if (0) {
// 		for (int i = 2; i <= n - 2; i++) {
// 			cnt++;
// 			ans[i] = true;
// 		}
// 	} else {
// 		ll last = 0;
// 		for (ll i = 2; i < n; i++) {
// 			if (ans[i]) {
// 				continue;
// 			}
// 			ll m = mod_reverse(i, n);
// 			if (m == -1) {
// 				continue;
// 			} else if (ans[m]) {
// 				continue;
// 			} else if (m == i) {
// 				if (last == 0) {
// 					last = i;
// 				} else {
// 					ll l = last * i;
// 					l %= n;
// 					/* cnt += 3;
// 					ans[last] = ans[i] = ans[l] = true;
// 					last = 0; */
// 					if (ans[l]) {
// 						cnt++;
// 						ans[l] = false;
// 						ans[last] = ans[i] = true;
// 						last = l;
// 					} else {
// 						cnt += 3;
// 						ans[l] = ans[last] = ans[i] = true;
// 						last = 0;
// 					}
// 				}
// 			} else {
// 				cnt += 2;
// 				ans[i] = ans[m] = true;
// 			}
// 		}
// 	}
// 	cout << cnt << endl;
// 	for (int i = 1; i <= n; i++) {
// 		if (ans[i]) {
// 			printf("%d ", i);
// 		}
// 	}
// 	puts("");
// 	return 0;
// }

int main()
{
	cin >> n;
	vector<int> out;
	ll p = 1;
	for (int i = 1; i <= n; i++) {
		if (__gcd(i, n) == 1) {
			p *= i;
			p %= n;
			out.push_back(i);
		}
	}
	if (p == 1) {
		printf("%d\n", out.size());
		for (int i = 0; i < out.size(); i++) {
			printf("%d ", out[i]);
		}
	} else {
		printf("%d\n", out.size() - 1);
		for (int i = 0; i < out.size(); i++) {
			if (out[i] != p) {
				printf("%d ", out[i]);
			}
		}
	}
	return 0;
}