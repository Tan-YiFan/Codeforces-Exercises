#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000 + 3;
int T;
long long x[N], y[N];
long long px[N], py[N];
int n;
int main()
{
    for (cin >> T; T; T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
        }
        sort(x + 1, x + n + 1);
        sort(y + 1, y + n + 1);
        for (int i = 1; i <= n; i++) {
            px[i] = px[i - 1] + x[i];
            py[i] = py[i - 1] + y[i];
        }
        if (n & 1) {
            cout << 1 << endl;
        }
        else {
            n >>= 1;
            cout << (x[n + 1] - x[n] + 1) * (y[n + 1] - y[n] + 1) << endl;
        }
    }
}