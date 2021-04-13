#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3000 + 10;
int T;
typedef long long ll;
int n;
char s[N][N];
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%s", &(s[i][1]));
		}
		int x[2], y[2];
		int cur = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (s[i][j] == '*') {
					x[cur] = i;
					y[cur] = j;
					cur++;
				}
			}
		}
		if (x[0] == x[1]) {
			if (x[0] == 1) {
				s[n][y[0]] = s[n][y[1]] = '*';
			} else {
				s[1][y[0]] = s[1][y[1]] = '*';
			}
		} else if (y[0] == y[1]) {
			if (y[0] == 1) {
				s[x[0]][n] = s[x[1]][n] = '*';
			} else {
				s[x[0]][1] = s[x[1]][1] = '*';
			}
		} else {
			s[x[0]][y[1]] = s[x[1]][y[0]] = '*';
		}
		for (int i = 1; i <= n; i++) {
			puts(&(s[i][1]));
		}
	}
	return 0;
}