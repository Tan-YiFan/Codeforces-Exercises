#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000 + 10;
const int MOD = 1e9 + 7;
int T;
typedef long long ll;
int n, k;
ll a[N][N], sum[N][N], dp[N][N][2];
ll solve(int q, int l, int r)
{
    if (q == 1) {
        return 1;
    }
    if (r == 0) {
        return 1;
    } 
    
    return (solve(q, l + 1, r - 1) + solve(q - 1, r, l)) % MOD;
    /* if (q == 1 || r == 0) {
        return 1;
    } 
    ll ans = 1;
    for (int i = 0; i < r; i++) {
        ans += solve(q - 1, i) % MOD;
    }
    return ans; */
}
constexpr int MX = N;

void initial()
{
    for (int i = 1; i <= MX; i++) {
        a[0][i] = 1;
        sum[0][i] = 1;
    }
    for (int i = 1; i <= MX; i++) {
        a[i][1] = 1;
        sum[i][1] = sum[i - 1][1] + 1;
    }
    for (int i = 1; i <= MX; i++) {
        for (int j = 1; j <= MX; j++) {
            a[i][j] = 1 + sum[i - 1][j - 1];
            a[i][j] %= MOD;
            sum[i][j] = (a[i][j] + sum[i - 1][j]) % MOD;
            
        }
    }
}

ll solve(int cur, int k, int dir, int zero)
{
    if (k == 1) {
        return 1;
    }
    if (dp[cur][k][dir] != -1) {
        return dp[cur][k][dir];
    }
    ll ans = 2;
    if (dir == 1) {
        if (cur < n) {
            ans += solve(cur + 1, k, dir, 0) - 1;
            ans %= MOD;
            ans += MOD;
            ans %= MOD;
        }
        ans %= MOD;
        if (cur > 1) {
            ans += solve(cur - 1, k - 1, 1 - dir, 0) - 1;
            ans %= MOD;
            ans += MOD;
            ans %= MOD;
        }
        ans %= MOD;
        dp[cur][k][dir] = ans;
    } else {
        if (cur > 1) {
            ans += solve(cur - 1, k, dir, 0) - 1;
            ans %= MOD;
            ans += MOD;
            ans %= MOD;
        }
        ans %= MOD;
        if (cur < n) {
            ans += solve(cur + 1, k - 1, 1 - dir, 0) - 1;
            ans %= MOD;
            ans += MOD;
            ans %= MOD;
        }
        ans %= MOD;
        dp[cur][k][dir] = ans;
    }
    return ans;
}
int main()
{
    /* initial();
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (a[i][j] != solve(j, 0, i)) {
                printf("error: n = %d, k = %d, a[n][k] = %d, solve = %d\n", i, j, a[i][j], solve(j, 0, i));
            } 
        }
    } */
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &n, &k);
        memset(dp, -1, sizeof(dp));
        printf("%lld\n", solve(1, k, 1, 0));
    }
    return 0; 
}