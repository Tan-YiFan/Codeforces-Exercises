#include <bits/stdc++.h>
using namespace std;

constexpr int N = 40000 + 3;
int T;
int n;
int a[N];
int up;
void prepare() 
{
    up = sqrt(2000000000);
    up = (up - 1) >> 1;
    for (int i = 1; i <= up; i++) {
        int j = (i << 1) + 1;
        a[i] = (j * j + 1) >> 1;
    }
}
int bin_search(int n)
{
    int hi = up + 1, lo = 0;
    // int mi = (hi + lo) >> 1;
    while (lo < hi - 1) {
        int mi = (hi + lo) >> 1;
        if (a[mi] == n) {
            return mi;
        } else if (a[mi] < n) {
            lo = mi;
        } else {
            hi = mi;
        }
        
    }
    return lo;
}
int main()
{
    prepare();
    // cout << 1 << endl;
    for (cin >> T; T; T--)
    {
        cin >> n;
        cout << bin_search(n) << endl;
    }
    // for (int i = 1; i <= 10; i++) {
    //     cout << a[i] << endl;
    // }
    
}