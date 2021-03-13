#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n;
int a[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        a[n + 1] = a[n] + 2;
        for (int i = n; i; i--) {
            if (a[i] + 1 < a[i + 1]) {
                a[i]++;
            } 
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != a[i + 1]) {
                ans++;
            } 
        }
        printf("%d\n", ans);
    }
    return 0;
}