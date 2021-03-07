#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        int sum = 0;
        int ones = 0;
        for (int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            sum += a;
            if (a == 1) {
                ones++;
            } 
        }
        if ((sum & 1) || (ones == 0 && (sum % 4))) {
            puts("NO");
        } else {
            puts("YES");
        }
    }
    return 0;
}