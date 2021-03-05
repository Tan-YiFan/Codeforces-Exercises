#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n1, n2, n3;
ll a1[N], a2[N], a3[N];
ll a[N];
ll sum1, sum2, sum3;
int len;
int main()
{
    scanf("%d %d %d", &n1, &n2, &n3);
    /* for (int i = 1; i <= n1 + n2 + n3; i++) {
        scanf("%lld", a + i);
    } */
    for (int i = 1; i <= n1; i++) {
        scanf("%lld", a1 + i);
        a[++len] = a1[i];
        sum1 += a1[i];
    }
    for (int i = 1; i <= n2; i++) {
        scanf("%lld", a2 + i);
        a[++len] = a2[i];
        sum2 += a2[i];
    }
    for (int i = 1; i <= n3; i++) {
        scanf("%lld", a3 + i);
        a[++len] = a3[i];
        sum3 += a3[i];
    }
    sort(a + 1, a + n1 + n2 + n3 + 1);
    sort(a1 + 1, a1 + n1 + 1);
    sort(a2 + 1, a2 + n2 + 1);
    sort(a3 + 1, a3 + n3 + 1);
    int n = min(n3, min(n1, n2));
    ll sum = sum1 + sum2 + sum3;
    // if (sum1 <= min(a2[1], a3[1])) {
    //     sum -= sum1 << 1;
    // } else if (sum2 <= min(a1[1], a3[1])) {
    //     sum -= sum2 << 1;
    // } else if (sum3 <= min(a1[1], a2[1])) {
    //     sum -= sum3 << 1;
    // } else {
    //     if (n1 == 1 && n2 == 1 && n3 == 1) {
    //         sum -= a[1] << 1;
    //     } else if (n1 == 1 && n2 == 1) {
    //         sum -= min(a1[1], a2[1]);
    //     } else if (n1 == 1 && n3 == 1) {
    //         sum -= min(a1[1], a3[1]);
    //     } else if (n2 == 1 && n3 == 1) {
    //         sum -= min(a2[1], a3[1]);
    //     } else if (n1 == 1) {
            
    //     } else if (n2 == 1) {
            
    //     } else if (n3 == 1) {
            
    //     } else {
            
    //     }
    // }
    ll src1 = a1[1] + a2[1];
    ll src2 = a2[1] + a3[1];
    ll src3 = a1[1] + a3[1];
    ll src4 = sum1;
    ll src5 = sum2;
    ll src6 = sum3;
    ll src = min(src1, min(src2, min(src3, min(src4, min(src5, src6)))));
    sum -= src << 1;
    printf("%lld\n", sum);
    return 0;
}