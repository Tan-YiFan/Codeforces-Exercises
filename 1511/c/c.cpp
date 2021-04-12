#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n, q;
int a[N], t[N];
// priority_queue<int> p[51];
int p[51];
bool k[51][51];
int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if (p[a[i]] == 0) {
			p[a[i]] = i;
			for (int j = 1; j <= 50; j++) {
				if (p[j] && j != a[i]) {
					k[a[i]][j] = true;
				}
			}
		}
	}
	int last = 0;
	for (int i = 1; i <= q; i++) {
		scanf("%d", t + i);
		printf("%d%c", p[t[i]], i == q ? '\n' : ' ');
		for (int j = 1; j <= 50; j++) {
			if (k[t[i]][j] && t[i] != j) {
				p[j]++;
				k[t[i]][j] = false;
				k[j][t[i]] = true;
			}
		}
		p[t[i]] = 1;
	}
	
	return 0;
}