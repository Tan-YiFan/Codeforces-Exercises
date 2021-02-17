#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
int n;
long long a[N], b[N], sum[N], diff[N], front[N], back[N];
bool ans[N];
int bin_search(long long *p, long long x)
{
    int lo = 1, hi = n + 1;
    while (lo < hi - 1) {
        int mi = (lo + hi) >> 1;
        if (p[mi] == x) {
            return mi;
        } else if (p[mi] < x) {
            lo = mi;
        } else {
            hi = mi;
        }
    }
    return lo;
}
int main()
{
    for (cin >> T; T; T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = a[i];
            // sum[i] = sum[i - 1] + a[i];
        }
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + b[i];
        }
        for (int i = 1; i <= n; i++) {
            diff[i] = sum[i - 1] - b[i];
        }
        for (int i = 1; i <= n; i++) {
            front[i] = min(front[i - 1], diff[i]);
        }
        for (int i = n; i > 0; i--) {
            back[i] = min(back[i + 1], diff[i]);
        }
        /* for (int i = 1; i <= n; i++) {
            printf("%d%c", diff[i], i == n ? '\n' : ' ');
        }
        for (int i = 1; i <= n; i++) {
            printf("%d%c", front[i], i == n ? '\n' : ' ');
        }
        for (int i = 1; i <= n; i++) {
            printf("%d%c", back[i], i == n ? '\n' : ' ');
        } */
        int num = 0;
        for (int i = 1; i <= n; i++) {
            int index = bin_search(b, a[i]);
            if (a[i] + front[index - 1] >= 0 && back[index + 1] >= 0) {
                // cout << i << ' ';
                ans[i] = true;
                num++;
            } 
        }
        // cout << endl;
        cout << num << endl;
        for (int i = 1; i <= n; i++) {
            
            if (ans[i]) {
                num--;
                printf("%d%c", i, num == 0 ? '\n' : ' ');
            } 
        }
        memset(b, 0, (n + 3) << 3);
        memset(sum, 0, (n + 3) << 3);
        memset(diff, 0, (n + 3) << 3);
        memset(front, 0, (n + 3) << 3);
        memset(back, 0, (n + 3) << 3);
        memset(ans, 0, (n + 3));
    }
}