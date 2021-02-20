#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100 + 3;
int T;
long long prefix[N];
int main()
{
    for (cin >> T; T; T--)
    {
        int n;
        cin >> n;
        int a;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            prefix[i] = prefix[i - 1] + a;
        }
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (prefix[i] < (i - 1) * i / 2) {
                ok = false;
                break;
            } 
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
}