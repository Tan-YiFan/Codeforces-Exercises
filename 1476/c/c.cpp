#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
int n;
long long a[N], b[N], c[N];
long long len[N];

// reference
int main()
{
    for (cin >> T; T; T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        for (int i = 2; i <= n; i++) {
            if (b[i] == a[i]) {
                len[i] = c[i] + 1;
            } else {
                len[i] = c[i] + 1 + max(abs(b[i] - a[i]), len[i - 1] - abs(b[i] - a[i]));
            } 
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, len[i]);
        }
        cout << ans << endl;
        memset(len + 1, 0, (n + 1) << 3);
    }
}