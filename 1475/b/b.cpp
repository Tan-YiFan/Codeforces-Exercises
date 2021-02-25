#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000000 + 10;
int T;
typedef long long ll;
bool ans[N];
int main()
{
    for (int i = 0; i <= 1000000 / 2020; i++) {
        for (int j = 0; (2020 * i + 2021 * j) <= 1000000; j++) {
            ans[2020 * i + 2021 * j] = true;
        }
    }
    for (cin >> T; T; T--)
    {
        int n;
        cin >> n;
        if (ans[n]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}