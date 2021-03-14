#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100 + 10;
int T;
typedef long long ll;
int n, k;
char s[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &n, &k);
        scanf("%s", s + 1);
        bool ok = true;
        if (n == (k << 1)) {
            ok = false;
        } 
        for (int i = 1; i <= k; i++) {
            if (s[i] != s[n - i + 1]) {
                ok = false;
                break;
            } 
        }
        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}