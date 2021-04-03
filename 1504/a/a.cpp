#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
char s[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%s", s + 1);
        bool ok = false;
        int n = strlen(s + 1);
        for (int i = 1; i <= n; i++) {
            if (s[i] != 'a') {
                ok = true;
            }
        }
        if (!ok) {
            puts("NO");
        } else {
            puts("YES");
            for (int i = n; i; i--) {
                if (s[i] != 'a') {
                    putchar('a');
                    puts(s + n - i + 1);
                    break;
                } else {
                    putchar(s[n - i + 1]);
                }
            }
        }
    }
    return 0;
}