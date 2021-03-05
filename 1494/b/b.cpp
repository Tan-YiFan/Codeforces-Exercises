#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n, u, r, d, l;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d %d %d %d", &n, &u, &r, &d, &l);
        bool solve = false;
        for (int i = 0; i < 16; i++) {
            int j = i;
            int ul = j / 8;
            j %= 8;
            int ur = j / 4;
            j %= 4;
            int dl = j / 2;
            j %= 2;
            int dr = j;
            if (ul + ur > u || 2 - (ul + ur) > n - u) {
                continue;
            }
            if (ul + dl > l || 2 - (ul + dl) > n - l) {
                continue;
            }
            if (dl + dr > d || 2 - (dl + dr) > n - d) {
                continue;
            }
            if (ur + dr > r || 2 - (ur + dr) > n - r) {
                continue;
            }
            solve = true;
            break;
        }
        if (solve) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}