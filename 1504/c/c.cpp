#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n;
char s[N], a[N], b[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        scanf("%s", s + 1);
        a[n + 1] = b[n + 1] = '\0';
        a[1] = b[1] = '(';
        a[n] = b[n] = ')';
        bool ok = true;
        if (s[1] != '1' || s[n] != '1') {
            ok = false;
        }
        int z = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') {
                z++;
            }
        }
        if (z & 1) {
            ok = false;
        }
        bool l = true;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') {
                a[i] = l ? '(' : ')';
                b[i] = l ? ')' : '(';
                l = !l;
            }
        }
        int cnt = 0, tot = (n - z) >> 1;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') {
                b[i] = a[i] = cnt < tot ? '(' : ')';
                cnt++;
            }
        }
        if (ok) {
            puts("YES");
            puts(a + 1);
            puts(b + 1);
        } else {
            puts("NO");
        }
    }
    return 0;
}