#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 3;
int T;
string s;
int x, y;
int main()
{
    for (cin >> T; T; T--)
    {
        s.clear();
        cin >> x >> y >> s;
        int l = 0, r = 0, u = 0, d = 0;
        for (auto& c : s) {
            switch (c) {
            case 'L':
                l++;
                break;
            case 'R':
                r++;
                break;
            case 'U':
                u++;
                break;
            case 'D':
                d++;
                break;
            default:
                ;
            }
        }
        bool ok = true;
        if (x > 0) {
            ok &= (r >= x);
        } else {
            ok &= (l >= -x);
        }
        if (y > 0) {
            ok &= (u >= y);
        } else {
            ok &= (d >= -y);
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}