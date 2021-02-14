#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 3;
int T;
int a[N];
int main()
{
    int n, q, k;
    cin >> n >> q >> k;
    for (int i = 1; i <= n; i++) {
        // cin >> a[i];
        scanf("%d", a + i);
    }
    int l, r;
    for (int i = 1; i <= q; i++) {
        // int l, r;
        // cin >> l >> r;
        scanf("%d %d", &l, &r);
        // cout << (k - a[r]) + (a[l] - 1) + 2 * (a[r] - a[l] - r + l) << endl;
        int ans = a[r] - a[l] + k - 1 - ((r - l) << 1);
        // cout << ans << endl;
        printf("%d\n", ans);
    }
    
}