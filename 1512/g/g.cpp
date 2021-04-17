#include <bits/stdc++.h>
using namespace std;

constexpr int N = 10000000 + 10;
int T;
typedef long long ll;
ll s[N];
int d[N], ans[N];
void initial()
{
	d[1] = 1;
	for (int i = 2; i * i < N; i++) {
		if (d[i] == 0) {
			d[i] = i;
			for (int j = i * i; j <= N; j += i) {
				if (d[j] == 0) {
					d[j] = i;
				}
			}
		}
	}
	s[1] = 1;
	for (int i = 2; i < N; i++) {
		if (d[i] == 0) {
			d[i] = i;
			s[i] = i + 1;
		} else {
			int j = i;
			s[i] = 1;
			while (j % d[i] == 0) {
				j /= d[i];
				s[i] = s[i] * d[i] + 1;
			}
			s[i] *= s[j];
		}
	}
	for (int i = N - 1; i; i--) {
		if (s[i] < N) {
			ans[s[i]] = i;
		}
	}
}
int main()
{
	initial();
	for (scanf("%d", &T); T; T--) {
		int k;
		cin >> k;
		cout << (ans[k] ? ans[k] : -1) << endl;
	}
	return 0;
}