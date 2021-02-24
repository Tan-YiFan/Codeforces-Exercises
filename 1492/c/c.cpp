#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int m, n;
char s[N], t[N];
int p[N], l[N], r[N];
// reference
int main()
{
    scanf("%d %d", &n, &m);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    int j = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == t[j]) {
            l[j++] = i;
        } 
    }
    j = m;
    for (int i = n; i; i--) {
        if (s[i] == t[j]) {
            r[j--] = i;
        } 
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(r[i + 1] - l[i], ans);
    }
    cout << ans << endl;
    return 0;
}