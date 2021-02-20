#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 3;
int T;
int n;
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

int solve(int lo, int hi)
{
    if (lo >= hi) {
        return lo;
    }
    else if (lo == hi - 1) {
        if (get(lo, hi) == lo) {
            return hi;
        } else {
            return lo;
        }
    }
    int mi = (lo + hi) >> 1;
    int second = get(lo, hi);
    if (mi > second) {
        if (get(lo, mi) == second) {
            return solve(lo, mi);
        } else {
            return solve(mi + 1, hi);
        }
    } else {
        if (get(mi, hi) == second) {
            return solve(mi, hi);
        } else {
            return solve(lo, mi - 1);
        }
    }
}
int main()
{
    m.clear();
    cin >> n;
    output(solve(1, n));
    return 0;
}
