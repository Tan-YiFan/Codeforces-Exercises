#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n;
int a[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            mx = max(mx, a[i]);
        }
        int pos = -1, neg = -1;
        bool zero = false;
        bool ok = true;
        for (int i = 2; i <= n; i++) {
            if (a[i] > a[i - 1]) {
                if (pos != -1 && a[i] - a[i - 1] != pos) {
                    ok = false;
                    break;
                }
                pos = a[i] - a[i - 1];
            } else if (a[i] < a[i - 1]) {
                if (neg != -1 && a[i - 1] - a[i] != neg) {
                    ok = false;
                    break;
                }
                neg = a[i - 1] - a[i];
            } else {
                zero = true;
            }
        }
        if (!ok) {
            puts("-1");
        } else {
            if (pos == -1 && neg == -1) {
                puts("0");
            } else if (zero) {
                puts("-1");
            } else if (pos == -1 || neg == -1) {
                puts("0");
            } else if (pos + neg <= mx) {
                puts("-1");
            } else {
                printf("%d %d\n", pos + neg, pos);
            }
        }
    }
    return 0;
}