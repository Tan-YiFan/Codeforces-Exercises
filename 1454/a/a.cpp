#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n;
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			printf("%d%c", i == 0 ? n : i, i == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}