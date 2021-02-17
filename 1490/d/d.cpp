#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100 + 3;
int T;
int pa[N], a[N], d[N];
int n;
int findmax(int lo, int hi, int p)
{
    int maxindex = lo;
    int maxvalue = a[lo];
    for (int i = lo; i < hi; i++) {
        if (a[i] > maxvalue) {
            maxindex = i;
            maxvalue = a[i];
        } 
    }
    d[maxindex] = d[p] + 1;
    return maxindex;
}
void solve(int lo, int hi, int p)
{
    if (lo >= hi) {
        return;
    } 
    int maxindex = findmax(lo, hi, p);
    pa[maxindex] = p;
    solve(lo, maxindex, maxindex);
    solve(maxindex + 1, hi, maxindex);
}
int main()
{
    for (cin >> T; T; T--)
    {
        memset(pa, 0, sizeof(pa));
        memset(d, 0, sizeof(d));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        solve(1, n + 1, 0);
        for (int i = 1; i <= n; i++) {
            printf("%d%c", d[i] - 1, i == n ? '\n' : ' ');
        }
    }
}