#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n;
int p[N];
int left_rise[N], right_rise[N];
int left_drop[N], right_drop[N];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", p + i);
	}
	int mx = 0;
	int obj = 0;
	for (int i = 2; i <= n; i++) {
		if (p[i] > p[i - 1]) {
			left_rise[i] = left_rise[i - 1] + 1;
			left_drop[i] = 0;
		} else {
			left_drop[i] = left_drop[i - 1] + 1;
			left_rise[i] = 0;
		}
		if (left_drop[i] > mx) {
			mx = max(left_drop[i], mx);
			obj = i - mx;
		} else if (left_drop[i] == mx) {
			obj = 0;
		}
		
	}
	// printf("obj:%d\n", obj);
	for (int i = n - 1; i; i--) {
		if (p[i] < p[i + 1]) {
			right_rise[i] = right_rise[i + 1] + 1;
			right_drop[i] = 0;
		} else {
			right_drop[i] = right_drop[i + 1] + 1;
			right_rise[i] = 0;
		}
		if (right_rise[i] > mx) {
			obj = i + mx;
			mx = max(right_rise[i], mx);
		} else if (right_rise[i] == mx && i != obj - mx) {
			obj = 0;
		}
	}
	// printf("obj:%d\n", obj);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		// printf("l:%d, r:%d\n", left_rise[i], right_drop[i]);
		int temp = max(right_drop[i], left_rise[i]);
		if ((temp != 0) && (temp % 2 == 0) && (right_drop[i] == left_rise[i]) && (obj == i)) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}