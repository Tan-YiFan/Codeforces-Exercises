#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000 + 10;
int T;
typedef long long ll;
int n, k;
int ans[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &n, &k);
        int len = 0;
        for (int i = k + 1; i <= n; i++) {
            ans[++len] = i;
        }
        for (int i = (k + 1) >> 1; i < k; i++) {
            ans[++len] = i;
        }

        printf("%d\n", len);
        for (int i = 1; i <= len; i++) {
            printf("%d%c", ans[i], i == len ? '\n' : ' ');
        }
    }
    return 0;
}