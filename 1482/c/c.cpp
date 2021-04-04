#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n, m;
int k[N];
int f[N];
int num[N];
int ans[N];
int exist[N];

// reference
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        int len = 0;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            num[i] = 0;
            exist[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", k + i);
            for (int j = 1; j <= k[i]; j++) {
                scanf("%d", &f[++len]);
                num[f[len]]++;
            }
            k[i] += k[i - 1];
        }
        
        bool ok = true;
        int mx_index = 0;
        for (int i = 1; i <= m; i++) {
            ans[i] = f[k[i - 1] + 1];
            exist[ans[i]]++;
            if (exist[ans[i]] > (m + 1) >> 1) {
                mx_index = ans[i];
            }
        }
        if (mx_index != 0) {
            ok = false;
            for (int i = 1; i <= m; i++) {
                if (ans[i] == mx_index && k[i] != k[i - 1] + 1) {
                    ans[i] = f[k[i]];
                    exist[mx_index]--;
                    if (exist[mx_index] <= (m + 1) >> 1) {
                        ok = true;
                        break;
                    }
                }
            }
        }

        if (!ok) {
            puts("NO");
            continue;
        }
        puts("YES");
        for (int i = 1; i <= m; i++) {
            printf("%d%c", ans[i], i == m ? '\n' : ' ');
        }
    }
    return 0;
}