#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000000;
int T;
typedef long long ll;
int ans[N + 1];
/* int solve(int cur, int k, int obj); */
int pre[N];
void initial()
{
    for (int i = 1; i <= 10000; i++) {
        pre[i] = pre[i - 1] + i;
        if (pre[i] >= N + N) {
            break;
        }
    }
    int l = 1;
    for (int i = 1; i <= N; i++) {
        /* ans[i] = solve(0, 1, i); */
        if (i == pre[l]) {
            ans[i] = l;
            l++;
        } else if (i == pre[l] - 1){
            ans[i] = l + 1;
        } else {
            ans[i] = l;
        }
    }
}
/* int solve(int cur, int k, int obj)
{
    if (cur + k == obj) {
        return k + 1;
    } else if (cur > N + 100 || cur < - N - 100) {
        return N + N;
    } else {
        return min(solve(cur + k, k + 1, obj), solve(cur - 1, k + 1, obj));
    }
} */
int main()
{
    initial();
    for (scanf("%d", &T); T; T--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    return 0;
}