#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100 + 3;
int T;
int n, k;
int h[N];

int main()
{
    for (cin >> T; T; T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
        }
        h[n + 1] = 0;
        bool ok = true;
        for (int i = 1; i <= k; i++) {
            int j = 1;
            while (j <= n) {
                if (h[j] < h[j + 1]) {
                    h[j] ++;
                    break;
                }
                j++;
            }
            if (j > n) {
                ok = false;
                break;
            }
            if (i == k) {
                cout << j << endl;
            } 
        }
        if (!ok) {
            cout << -1 << endl;
        } 
    }
}