#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
long long p, a, b, c;
long long count(long long x, long long y)
{
    if (x % y) {
        return y - (x % y);
    } else {
        return 0;
    }
}
int main()
{
    for (cin >> T; T; T--)
    {
        cin >> p >> a >> b >> c;
        cout << min(min(count(p, a), count(p, b)), count(p, c)) << endl;
    }
    return 0;
}