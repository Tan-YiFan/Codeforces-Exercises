#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100 + 10;
int T;
typedef long long ll;
int n;
int num[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        int mx = 0;
        memset(num, 0, sizeof(num));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            num[a]++;
            mx = max(mx, num[a]);
        }
        printf("%d\n", mx);
    }
    return 0;
}