#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n;
char s[N];
// int ans[N];
int l[N][2], r[N][2];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        scanf("%s", s + 1);

        for (int i = 1; i <= n + 1; i++) {
            l[i][0] = 0;
            l[i][1] = 0;
            r[i][0] = 0;
            r[i][1] = 0;
        }
        for (int i = 2; i <= n + 1; i++) {
            if (s[i - 1] == 'L') {
                l[i][0] = l[i - 1][1] + 1;
                l[i][1] = 0;
            } else {
                l[i][0] = 0;
                l[i][1] = l[i - 1][0] + 1;
            }
        }
        for (int i = n; i; i--) {
            if (s[i] == 'R') {
                r[i][0] = r[i + 1][1] + 1;
                r[i][1] = 0;
            } else {
                r[i][0] = 0;
                r[i][1] = r[i + 1][0] + 1;
            }
        }
        for (int i = 1; i <= n + 1; i++) {
            printf("%d%c", l[i][0] + r[i][0] + 1, i == (n + 1) ? '\n' : ' ');
        }
    }
    return 0;
}