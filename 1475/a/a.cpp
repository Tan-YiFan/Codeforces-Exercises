#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
ll n;
int main()
{
    
    for (cin >> T; T; T--)
    {
        cin >> n;
        while ((n & 1) == 0) {
            n >>= 1;
        }
        if (n == 1) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}