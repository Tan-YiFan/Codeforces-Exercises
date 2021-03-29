#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n, W;
int w[N];
int bit_W[32], bit_w[32];
void getbits_W()
{
    memset(bit_W, 0, sizeof(bit_W));
    int temp = W;
    for (int i = 0; i < 32; i++) {
        if (temp & 1) {
            bit_W[i]++;
        }
        temp >>= 1;
    }
}
void getbits_w(int k)
{
    int temp = k;
    for (int i = 0; i < 32; i++) {
        if (temp & 1) {
            bit_w[i]++;
        }
        temp >>= 1;
    }
}
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &n, &W);
        getbits_W();
        memset(bit_w, 0, sizeof(bit_w));
        for (int i = 1; i <= n; i++) {
            scanf("%d", w + i);
            getbits_w(w[i]);
        }
        /* for (int i = 0; i < 32; i++) {
            printf("%d%c", bit_W[i], i == 31 ? '\n' : ' ');
        }
        for (int i = 0; i < 32; i++) {
            printf("%d%c", bit_w[i], i == 31 ? '\n' : ' ');
        } */
        ll ans = 0;
        for (int i = 31; i >= 0; i--) {
            while (bit_w[i]) {
                ans++;
                for (int j = 31; j >= 0; j--) {
                    if (bit_W[j]) {
                        int remain = 1 << (j - min(i, j));
                        for (int k = min(i, j); k >= 0; k--) {
                            if (bit_w[k] >= remain) {
                                bit_w[k] -= remain;
                                remain = 0;
                            } else {
                                remain -= bit_w[k];
                                bit_w[k] = 0;
                            }
                            remain <<= 1;
                        }
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}