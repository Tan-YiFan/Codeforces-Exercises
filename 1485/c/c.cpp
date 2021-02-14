#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 3;
int T;
constexpr int M = 40000;
// long long a[M][M];
int main()
{
    
    for (cin >> T; T; T--)
    {
        int x, y;
        cin >> x >> y;
        // cout << a[x][y] << endl;
        long long ans = 0;
        int k = sqrt(x);
        k = min(k, y);
        for (int i = 1; i <= k; i++) {
            int max1 = (x - i) / i - i;
            max1 = max(0, max1);
            int max2 = y - i;
            ans += min(max1, max2);
        }
        cout << ans << endl;
    }
}