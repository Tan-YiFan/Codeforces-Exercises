#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100 + 10;
int T;
typedef long long ll;
int a[N];
int u, v;
int n;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d %d", &n, &u, &v);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        bool flag1 = false, flag2 = false;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i + 1]) {
                flag1 = true;
            }
            if (abs(a[i] - a[i + 1]) >= 2) {
                flag2 = true;
            } 
        }
        if (flag2) {
            puts("0");
        } else if (flag1) {
            printf("%d\n", min(u, v));
        } else {
            printf("%d\n", v + min(u, v));
        }
    }
    return 0;
}