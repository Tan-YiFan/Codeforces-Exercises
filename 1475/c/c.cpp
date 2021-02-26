#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int fir[N], sec[N];
int numa[N], numb[N];
int a, b, k;
int main()
{
    for (cin >> T; T; T--)
    {
        cin >> a >> b >> k;
        for (int i = 1; i <= k; i++) {
            cin >> fir[i];
            numa[fir[i]]++;
        }
        for (int i = 1; i <= k; i++) {
            cin >> sec[i];
            numb[sec[i]]++;
        }
        long long ans = 0;
        for (int i = 1; i <= k; i++) {
            ans += k - numa[fir[i]] - numb[sec[i]] + 1;
        }
        ans >>= 1;
        cout << ans << endl;
        memset(numa + 1, 0, a << 2);
        memset(numb + 1, 0, b << 2);
    }
    return 0;
}