#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
int n, m;
long long a, x;
long long pref[N];
int len;
int ord[N];
int bin_search(long long x, int lo, int hi)
{
    if (x == 0) {
        return 0;
    } 
    // int lo = 1, hi = n + 1;
    while (lo < hi) {
        int mi = (lo + hi) >> 1;
        if (pref[mi] >= x) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    return lo;
}
long long round_up(long long x, long long y)
{
    if (y == 0) {
        return 0;
    }
    if (x <= 0) {
        return 0;
    } 
    return (x + y - 1) / y;
}
int main()
{
    for (cin >> T; T; T--)
    {
        cin >> n >> m;
        long long maxpref = -1000000001;
        long long prefsum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            // pref[i] = pref[i - 1] + a;
            prefsum += a;
            if (prefsum > pref[len]) {
                pref[++len] = prefsum;
                ord[len] = i;
            } 
            maxpref = max(prefsum, maxpref);
        }
        // long long prefall = pref[n];
        // sort(ord + 1, ord + n + 1, [](int x, int y) {return pref[x] < pref[y];});
        // sort(pref + 1, pref + n + 1);
        for (int i = 1; i <= m; i++) {
            cin >> x;
            if (x > maxpref && prefsum <= 0) {
                cout << -1 << ' ';
            }
            else {
                long long ans = (round_up(x - maxpref, prefsum)) * n;
                x -= (round_up(x - maxpref, prefsum)) * prefsum;
                cout << ans + ord[bin_search(x, 1, len + 1)] - 1 << ' ';
            }
        }
        cout << endl;
        len = 0;
    }
}