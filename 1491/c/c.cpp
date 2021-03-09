#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5000 + 10;
int T;
typedef long long ll;
int n;
int S[N];
int addi[N];

// reference
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        int len = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", S + i);
            addi[i] = 0;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = min(n, i + S[i]); j >= i + 2; j--) {
                // cnt++;
                S[i]--;
                addi[j]++;
                if (addi[i]) {
                    addi[i]--;
                } else {
                    ans++;
                }
            }
            if (S[i] > 1) {
                if (S[i] - 1 - addi[i] > 0) {
                    ans += S[i] - 1 - addi[i];
                    addi[i] = 0;
                } else {
                    addi[i] -= S[i] - 1;
                }
            }
            addi[i + 1] += addi[i];
            // printf("%lld\n", ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}