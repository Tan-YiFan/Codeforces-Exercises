#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int a, b, c;
int ans[10];
void initial()
{
	ans[0] = 1;
	ans[1] = 1;
	ans[2] = 11;
	ans[3] = 101;
	ans[4] = 1021;
	ans[5] = 10007;
	ans[6] = 100003;
	ans[7] = 1000003;
	ans[8] = 10000019;
	ans[9] = 100000007;
}
int main()
{
	initial();
	for (scanf("%d", &T); T; T--)
	{
		scanf("%d %d %d", &a, &b, &c);
		int x = ans[a - c + 1] * ans[c];
		int y = (ans[b - c + 1] + 1) * ans[c];
		printf("%d %d\n", x, y);
	}
	return 0;
}