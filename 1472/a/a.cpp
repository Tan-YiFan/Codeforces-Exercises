#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int w, h, n;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d %d", &w, &h, &n);
        ll w_times = 1;
        while ((w & 1) == 0) {
            w_times <<= 1;
            w >>= 1;
        }
        ll h_times = 1;
        while ((h & 1) == 0) {
            h_times <<= 1;
            h >>= 1;
        }
        if (h_times * w_times >= n) {
            puts("YES");
        } else {
            puts("NO");
        }
        
    }
    return 0;
}