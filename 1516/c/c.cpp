#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
mt19937 rn(chrono::steady_clock::now().time_since_epoch().count());
int n;
int a[N];
bool exist[N];
vector<int> temp;
int main()
{
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	bool ok = false;
	if (sum & 1) {
		puts("0");
		return 0;
	}
	sum >>= 1;
	for (int i = 1; i <= n; i++) {
		int k = temp.size();
		for (int j = 0; j < k; j++) {
			if (!exist[temp[j] + a[i]]) {
				exist[temp[j] + a[i]] = true;
				temp.push_back(temp[j] + a[i]);
				if (sum == temp[j] + a[i]) {
					ok = true;
				}
			}
		}
		if (!exist[a[i]]) {
			temp.push_back(a[i]);
			exist[a[i]] = true;
			if (a[i] == sum) {
				ok = true;
			}
		}
	}
	if (!ok) {
		puts("0");
		return 0;
	}
	for (int _ = 0; _ < 15; _++) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] & 1) {
				cnt++;
			}
		}
		if (cnt & 1) {
			puts("0");
			return 0;
		}
		if (cnt == 0) {
			for (int i = 1; i <= n; i++) {
				a[i] >>= 1;
			}
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] & 1) {
				puts("1");
				printf("%d\n", i);
				return 0;
			}
		}
	}
	
	return 0;
}