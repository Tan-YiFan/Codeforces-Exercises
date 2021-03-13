#include <bits/stdc++.h>
using namespace std;

constexpr int N = 50 + 10;
int T;
typedef long long ll;
int n;
int a[N];
bool t[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                t[a[j] - a[i]] = true;
            }
        }
        int ans = 0;
        for (int i = 1; i <= a[n]; i++) {
            if (t[i]) {
                ans++;
                t[i] = false;
            } 
        }
        printf("%d\n", ans);
    }
    return 0;
}