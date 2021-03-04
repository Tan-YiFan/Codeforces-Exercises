#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int a[N];
int n;
// bool hv[N];
bool test(int i)
{
    if (i <= 1 || i >= n) {
        return false;
    }
    if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
        return true;
    }
    if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
        return true;
    }
    return false;
}
int counthv(int i)
{
    int ret = 0;
    if (test(i - 1)) {
        ret++;
    }
    if (test(i)) {
        ret++;
    }
    if (test(i + 1)) {
        ret++;
    }
    return ret;
}
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }

/*         int ans = 0;
        int subsequent = 0;
        bool sub2 = false;
        bool sub3 = false;
        for (int i = 2; i < n; i++) {
            if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
                ans++;
                subsequent++;
            } else if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
                ans++;
                subsequent++;
            } else {
                subsequent = 0;
            }
            if (subsequent == 2) {
                sub2 = true;
            }
            if (subsequent == 3) {
                sub3 = true;
            } 
        }
        bool sub1 = (ans >= 1);
        if (sub3) {
            ans -= 3;
        } else if (sub2) {
            ans -= 2;
        } else if (sub1) {
            ans--;
        } */
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (test(i)) {
                ans++;
                // hv[i] = true;
            } 
        }
        int rev = 0;
        for (int i = 1; i <= n; i++) {
            int oldnum = a[i];
            int oldsum = counthv(i);
            if (i < n) {
                a[i] = a[i + 1];
                int newsum = counthv(i);
                if (newsum < oldsum) {
                    rev = max(rev, oldsum - newsum);
                } 
            }
            if (i > 1) {
                a[i] = a[i - 1];
                int newsum = counthv(i);
                if (newsum < oldsum) {
                    rev = max(rev, oldsum - newsum);
                } 
            } 
            a[i] = oldnum;
        }
        printf("%d\n", ans - rev);
        // memset(hv + 1, 0, n);
    }
    return 0;
}