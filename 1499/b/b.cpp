#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100 + 10;
int T;
typedef long long ll;
char s[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%s", s + 1);
        int last_1 = 0, first_0 = 0;
        int n = strlen(s + 1);
        bool ok = true;
        int last = 0;
        for (int i = n; i > 1; i--) {
            if (s[i] == '0' && s[i - 1] == '0') {
                last = i;
                break;
            }
        }
        if (last == 0) {
            puts("YES");
            continue;
        }
        for (int i = last; i >= 1; i--) {
            if (s[i] == '1' && s[i - 1] == '1') {
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