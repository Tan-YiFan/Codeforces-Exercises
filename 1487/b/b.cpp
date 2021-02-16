#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 3;
int T;
int n, k;
int main()
{
    for (cin >> T; T; T--)
    {
        cin >> n >> k;
        int ans = k;
        if ((n & 1 == 1) && ((k << 1) >= n + 1)) {
            ans += (k - 1) / (n >> 1);
        } 
        
        if (ans % n == 0) {
            cout << n << endl;
        } else {
            cout << ans % n << endl;
        }
        
        
    }
}