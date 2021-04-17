#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n, k;
int a[N];
int b[N];
int pref[N], max_suff[N];
bool cmp(int mi)
{
	for (int i = 1; i <= n; i++) {
		if (a[i] < mi) {
			b[i] = -1;
		} else {
			b[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + b[i];
	}
	max_suff[n] = pref[n];
	for (int i = n - 1; i > 0; i--) {
		max_suff[i] = max(max_suff[i + 1], pref[i]);
	}
	bool ok = false;
	for (int i = 1; i <= n - k + 1; i++) {
		if (max_suff[i + k - 1] > pref[i - 1]) {
			ok = true;
			break;
		}
	}
	return ok;
}
int bin_search(int lo, int hi)
{
	while (lo < hi) {
		int mi = (lo + hi) >> 1;
		if (!cmp(mi)) {
			hi = mi;
		} else lo = mi + 1;
	}
	return --lo;
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << bin_search(1, n + 1) << endl;
	return 0;
}