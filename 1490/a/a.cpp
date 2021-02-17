#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 3;
int T;
int n;
int l, r;

int test(int a, int b)
{
    int ret = 0;
    while ((a << 1) < b) {
        a <<= 1;
        ret++;
    }
    return ret;
}

int main()
{
    for (cin >> T; T; T--)
    {
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> l;
            if (i != 1) {
                if (l < r) {
                    ans += test(l, r);
                } else {
                    
                    ans += test(r, l);
                }
            }
            r = l;
        }
        cout << ans << endl;
    }
}