#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n, k1, k2, w, b;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d %d", &n, &k1, &k2);
        scanf("%d %d", &w, &b);
        if (w + w <= k1 + k2 && b + b <= n + n - k1 - k2) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}