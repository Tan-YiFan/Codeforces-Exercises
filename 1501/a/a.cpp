#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100 + 10;
int T;
typedef long long ll;
int n;
int a[N], b[N];
int t[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", a + i, b + i);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", t + i);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int arrival = ans + a[i] - b[i - 1] + t[i];
            if (i == n) {
                ans = arrival;
                break;
            }
            ans = max(b[i], arrival + ((b[i] - a[i] + 1) >> 1));
        }
        printf("%d\n", ans);
    }
    return 0;
}