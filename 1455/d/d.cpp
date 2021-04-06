#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500 + 10;
int T;
typedef long long ll;
int n, x;
int a[N], b[N];
bool diff[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &n, &x);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            b[i] = a[i];
            diff[i] = false;
        }
        sort(b + 1, b + n + 1);
        bool needed = false;
        for (int i = 1; i <= n; i++) {
            if (b[i] != a[i]) {
                needed = true;
                break;
            }
        }
        if (!needed) {
            puts("0");
            continue;
        }
        bool ok = false;
        int ans = 501;
        for (int j = 1; j <= n; j++) {
            if (a[j] <= x) {
                continue;
            }
            for (int i = 1; i <= n; i++) {
                b[i] = a[i];
            }
            b[j] = 501;
            b[n + 1] = x;
            sort(b + 1, b + n + 2);
            int last = x;

            int temp = 0;
            bool fail = false;
            for (int i = 1; i <= n; i++) {
                if (b[i] != a[i] && a[i] < last) {
                    fail = true;
                    break;
                }
                if (b[i] != a[i]) {
                    temp++;
                    last = a[i];
                }
            }
            if (!fail) {
                ok = true;
                ans = min(ans, temp);
            }
        }
        if (!ok) {
            puts("-1");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}