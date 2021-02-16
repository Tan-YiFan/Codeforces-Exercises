#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100 + 3;
int T;
int n;
int a[N];
int main()
{
    for (cin >> T; T; T--)
    {
        cin >> n;
        int m = 101;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            m = min(a[i], m);
        }
        int ans = n;
        for (int i = 1; i <= n; i++) {
            if (a[i] == m) {
                ans--;
            } 
            
        }
        cout << ans << endl;
    }
}