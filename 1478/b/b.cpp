#include <bits/stdc++.h>
using namespace std;

constexpr int N = 10000 + 10;
int T;
typedef long long ll;
int q, d;
// int a[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &q, &d);
        int mx = d * 10;
        for (int i = 1; i <= q; i++) {
            // scanf("%d", a + i);
            bool found = false;
            int b;
            scanf("%d", &b);
            if (b >= mx || d == 1) {
                puts("YES");
                continue;
            } 
            while (b > 0) {
                if (b % d == 0) {
                    found = true;
                    break;
                }
                b -= 10;
            }
            if (found) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
        
    }
    return 0;
}