#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100 + 3;
int T;
long long n, k;
long long p[N];
long long prefix[N];

// a / b <= c / d ?
bool calculate(long long a, long long b, long long c, long long d)
{
    return a * d <= b * c;
}
int main()
{
    for (cin >> T; T; T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            prefix[i] = prefix[i - 1] + p[i];
        }
        long long ans = 0;
        for (int i = 2; i <= n; i++) {
            if (calculate(p[i], prefix[i - 1] + ans, k, 100) == false) {
                ans += (100 * p[i] - k * (prefix[i - 1] + ans) + k - 1) / k;
            } 
        }
        cout << ans << endl;
    }
}