#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n, k;
unordered_map<int, bool> m;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &n, &k);
        m.clear();
        int mex_value = 0, max_value = 0;
        int temp;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &temp);
            max_value = max(max_value, temp);
            if (!m[temp]) {
                ans++;
            } 
            m[temp] = true;
        }
        for (int i = 0; i <= n; i++) {
            if (!m[i]) {
                mex_value = i;
                break;
            } 
        }
        if (mex_value == n) {
            printf("%d\n", n + k);
            continue;
        } 
        for (int i = 1; i <= k; i++) {
            // printf("mex: %d, max: %d\n", mex_value, max_value);
            int ins = (mex_value + max_value + 1) >> 1;
            if (!m[ins]) {
                m[ins] = true;
                for (int j = mex_value; j <= n + i; j++) {
                    if (!m[j]) {
                        mex_value = j;
                        break;
                    } 
                }
                ans++;
                max_value = max(max_value, ins);
            } else {
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}