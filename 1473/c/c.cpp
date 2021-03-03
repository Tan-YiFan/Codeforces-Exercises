#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
ll n, k;
ll inversion_init()
{
    return (n - k + 1) * (n - k) / 2;
}

// b[1] = n = p[1], b[2] = n - 1 = p[2], b[3] = n - 2 = p[3]

// p : 1 2 3 4 5
// a : 1 2 3 4 5 4 3
// b : 1 2 3 4 5 4 3
// p : 1 2 3 5 4
// b : 1 2 3 5 4 5 3
// p : 1 2 5 3 4
// b : 1 2 5 3 4 3 5
// p : 1 2 4 5 3
// b : 1 2 4 5 3 5 4

// a : 1 2 3 4 5 4
// p : 1 2 3 5 4
// b : 1 2 3 5 4 5
// n = 7, k = 5, pref = 2; n = 6, k = 5, pref = 3
int ans[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%lld %lld", &n, &k);
        for (int i = 1; i <= k + k - n - 1; i++) {
            ans[i] = i;
        }
        for (int i = k + k - n; i <= k; i++) {
            ans[i] = k - i + k + k - n;
        }
        for (int i = 1; i <= k; i++) {
            printf("%d%c", ans[i], i == k ? '\n' : ' ');
        }
    }
    return 0;
}