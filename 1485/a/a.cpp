#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 3;
int T;
int main()
{
    
    for (cin >> T; T; T--)
    {
        int a, b;
        cin >> a >> b;
        int ans = max(a, 10);
        for (int i = 0; i < 8; i++)
        {
            if (b + i == 1) continue;
            int temp = i;
            int c = a, d = b + i;
            while (c) {
                c /= d;
                temp++;
            }
            ans = min(ans, temp);
        }
        
        cout << ans << endl;
    }
}