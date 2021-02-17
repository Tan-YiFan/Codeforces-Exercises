#include <bits/stdc++.h>
using namespace std;

constexpr int N = 30000 + 3;
int T;
int n;
// int a[N];
int a;
int c[3];
int k;
int main()
{
    for (cin >> T; T; T--)
    {
        memset(c, 0, sizeof(c));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            c[a % 3]++;
        }
        a = n / 3;
        k = 0;
        for (int i = 0; i < 3; i++) {
            k += (c[i] >= a);
        }
        switch (k) {
        case 3:
            cout << 0 << endl;
            break;
        case 2:
            if (c[0] < a) {
                cout << ((c[1] - a) << 1) + (c[2] - a) << endl;
            } else if (c[1] < a) {
                cout << ((c[2] - a) << 1) + (c[0] - a) << endl;
            } else {
                cout << ((c[0] - a) << 1) + (c[1] - a) << endl;
            }
            break;
        case 1:
            if (c[0] >= a) {
                cout << ((a - c[2]) << 1) + (a - c[1]) << endl;
            } else if (c[1] >= a) {
                cout << ((a - c[0]) << 1) + (a - c[2]) << endl;
            } else {
                cout << ((a - c[1]) << 1) + (a - c[0]) << endl;
            }
            break;
        default:
            ;
        }
        
    }
}