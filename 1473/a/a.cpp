#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100 + 10;
int T;
typedef long long ll;
int n, d;
int a[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &n, &d);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        sort(a + 1, a + n + 1);
        if (a[1] + a[2] <= d || a[n] <= d) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}