#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 3;
int T;
long long A, B, n;
long long a[N], b[N];
int main()
{
    for (cin >> T; T; T--)
    {
        long long maxAttack = 0;
        cin >> A >> B >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            maxAttack = max(a[i], maxAttack);
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        long long s = 0;
        for (int i = 1; i <= n; i++) {
            s += ((b[i] - 1) / A + 1) * a[i];
        }
        if (B >= s - maxAttack + 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        
        
    }
}