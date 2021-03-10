#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n, m;
char s[N];
int cur[N], max_cur[N], min_cur[N];
int l, r;
int surf[N], max_surf[N], min_surf[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &n, &m);
        scanf("%s", s + 1);
        for (int i = 1; i <= n; i++) {
            if (s[i] == '+') {
                cur[i] = cur[i - 1] + 1;
            } else {
                cur[i] = cur[i - 1] - 1;
            }
            max_cur[i] = max(max_cur[i - 1], cur[i]);
            min_cur[i] = min(min_cur[i - 1], cur[i]);
        }
        surf[n + 1] = 0;
        max_surf[n + 1] = 0;
        min_surf[n + 1] = 0;
        for (int i = n; i; i--) {
            if (s[i] == '+') {
                surf[i] = surf[i + 1] + 1;
            } else {
                surf[i] = surf[i + 1] - 1;
            }
            max_surf[i] = max(max_surf[i + 1], surf[i]);
            min_surf[i] = min(min_surf[i + 1], surf[i]);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &l, &r);
            int max_right = (cur[l - 1] + cur[n] - cur[r] - min_surf[r + 1]);
            int min_right = (cur[l - 1] + cur[n] - cur[r] - max_surf[r + 1]);
            int ans = max(max_cur[l - 1], max_right) - min(min_cur[l - 1], min_right);
            printf("%d\n", ans + 1);
        }
    }
    return 0;
}