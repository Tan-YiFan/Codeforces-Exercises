#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n;
struct Point {
	int x;
	int y;
};
vector<Point> v[11];
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		for (int i = 0; i < 10; i++) {
			v[i].clear();
		}
		scanf("%d", &n);
		getchar();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int temp = getchar();
				// putchar(temp);
				v[temp - '0'].push_back(Point{ i,j });
			}
			getchar();
		}
		for (int i = 0; i < 10; i++) {
			int ans = 0;
			Point s = Point{ 0,0 }, w = Point{ 0,0 }, e = Point{ 0,0 }, u = Point{ 0,0 };
			if (v[i].size() < 2) {
				printf("%d%c", ans, i == 9 ? '\n' : ' ');
				continue;
			}
			for (auto item : v[i]) {
				if (item.y > s.y || s.y == 0) {
					s = item;
				}
				if (item.y < u.y || u.y == 0) {
					u = item;
				}
				if (item.x > e.x || e.x == 0) {
					e = item;
				}
				if (item.x < w.x || w.x == 0) {
					w = item;
				}
			}
			for (auto &item : v[i]) {
				int h = max(item.x - 1, n - item.x);
				int v = max(item.y - 1, n - item.y);
				ans = max(ans, h * max(item.y - u.y, s.y - item.y));
				ans = max(ans, v * max(item.x - w.x, e.x - item.x));
			}
			printf("%d%c", ans, i == 9 ? '\n' : ' ');
		}
	}
	return 0;
}