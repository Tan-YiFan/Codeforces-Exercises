#include <bits/stdc++.h>
using namespace std;

// reference
constexpr int N = 100000 + 3;
int T;
int n;
int sec;
map<pair<int, int>, int> m;
void output(int ans)
{
    printf("! %d\n", ans);
}

int get(int lo, int hi)
{
    if (m[{lo, hi}]) {
        return m[{lo, hi}];
    } 
    printf("? %d %d\n", lo, hi);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    m[{lo, hi}] = ret;
    return ret;
}
int solvelo(int lo, int hi) // (lo, hi]
{
    while (lo < hi - 1) {
        int mi = (lo + hi) >> 1;
        if (get(sec, mi) != sec) { // first > mi
            lo = mi;
        } else {
            hi = mi;
        }
    }
    return hi;
}

int solvehi(int lo, int hi) // [lo, hi)
{
    while (lo < hi - 1) {
        int mi = (lo + hi + 1) >> 1;
        if (get(mi, sec) != sec) { // first < mi
            hi = mi;
        } else {
            lo = mi;
        }
    }
    return lo;
}
int main()
{
    cin >> n;
    sec = get(1, n);
    if (sec == 1 || get(1, sec) != sec) {
        output(solvelo(sec, n));
    } else {
        output(solvehi(1, sec));
    }
    return 0;
}