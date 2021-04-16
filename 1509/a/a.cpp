#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int a[N];
int ans[N];
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		int n;
		scanf("%d", &n);
		stack<int> p, q;
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			if (a[i] & 1) {
				p.push(a[i]);
			} else {
				q.push(a[i]);
			}
		}
		
		int len = 0;
		while (!p.empty()) {
			ans[++len] = p.top();
			p.pop();
		}
		while (!q.empty()) {
			ans[++len] = q.top();
			q.pop();
		}
		for (int i = 1; i <= n; i++) {
			printf("%d%c", ans[i], i == n ? '\n' : ' ');
		}
	}
	return 0;
}