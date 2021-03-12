#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int c[4];
int a[6];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        for (int i = 1; i <= 3; i++) {
            scanf("%d", c + i);
        }
        for (int i = 1; i <= 5; i++) {
            scanf("%d", a + i);
        }
        bool ans = true;
        for (int i = 1; i <= 3; i++) {
            if (c[i] < a[i]) {
                ans = false;
                break;
            }
            c[i] -= a[i];
        }
        a[4] -= min(a[4], c[1]);
        a[5] -= min(a[5], c[2]);
        if (c[3] < a[4] + a[5]) {
            ans = false;
        } 
        if (ans) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}