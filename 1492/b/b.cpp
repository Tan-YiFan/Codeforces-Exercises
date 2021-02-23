#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n;
int p[N];
int mx[N];
int ans[N];
int main()
{
    for (cin >> T; T; T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        mx[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (p[i] > p[mx[i - 1]]) {
                mx[i] = i;
            } else {
                mx[i] = mx[i - 1];
            }
        }
        /* for (int i = 1; i <= n; i++) {
            printf("%d%c", mx[i], i == n ? '\n' : ' ');
        } */
        int idx = n, cnt = 1;
        while (idx) {
            for (int i = mx[idx]; i <= idx; i++) {
                ans[cnt++] = p[i];
            }
            idx = mx[idx] - 1;
        }
        for (int i = 1; i <= n; i++) {
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}