#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n, q;
int a[N];
map<int, bool> m;
ll sum[N];
int bin_search(int lo, int hi, int value) // (lo, hi]
{
    // printf("%d %d ", lo, hi);
    while (lo < hi) {
        int mi = (lo + hi) >> 1;
        if (a[mi] > value) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    // printf("%d\n", lo);
    return --lo;
}
const int MAXS = 1000000000;
void add_into(ll k)
{
    if (k <= MAXS) {
        m[k] = true;
    } 
}
void solve(int lo, int hi)
{
    if (lo > hi) {
        return;
    }
    if (a[lo] == a[hi]) {
        add_into(sum[hi] - sum[lo - 1]);
        return;
    }
    int value = (a[lo] + a[hi]) >> 1;
    int mi = bin_search(lo - 1, hi, value);
    add_into(sum[hi] - sum[lo - 1]);
    solve(lo, mi);
    solve(mi + 1, hi);
}
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        m.clear();
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + a[i];
        }
        solve(1, n);
        for (int i = 1; i <= q; i++) {
            int s;
            scanf("%d", &s);
            if (m[s]) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }
    return 0;
}