#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n;
ll d[N];
ll pref[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        n <<= 1;
        int len = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", d + i);
        }
        stable_sort(d + 1, d + n + 1);
        bool found = true;
        ll sum = d[1] >> 1;
        // ll pref = 0;
        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                if (d[i] != d[i + 1] || (d[i] & 1)) {
                    found = false;
                    break;
                } 
            } else {
                if (i >= 3) {
                    // pref += (d[i] - d[i - 2]) >> 1;
                    if (((d[i] - d[i - 2]) % (i - 2)) || (d[i] == d[i - 2])) {
                        found = false;
                        break;
                    } 
                    pref[len + 1] = pref[len] + ((d[i] - d[i - 2]) / (i - 2));
                    len++;
                }    
            }
        }
        /* for (int i = 0; i <= len; i++) {
            printf("%lld%c", pref[i], i == len ? '\n' : ' ');
        } */
        // printf("%d %d %d\n", sum, pref, found);
        ll pref1 = 0;
        for (int i = 1; i <= len; i++) {
            pref1 += pref[i];
        }
        // printf("%d %d %d %d\n", sum, pref1, found, len);
        if (!found || pref1 >= sum || ((sum - pref1) % (n >> 1))) {
            puts("NO");
        } else {
            puts("YES");
        }
    }
    return 0;
}