#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n;
int h[N], w[N];
int ordh[N], ordw[N], minw[N], ans[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", h + i, w + i);
            if (h[i] > w[i]) {
                swap(h[i], w[i]); // ensure h[i] <= w[i]
            } 
            ordh[i] = i;
            ordw[i] = i;
        }
        w[n + 1] = 0;
        h[n + 1] = 0;
        ordh[n + 1] = 0;
        sort(ordh + 1, ordh + n + 1, [](int u, int v) {return h[u] < h[v];});
        // sort(ordw + 1, ordw + n + 1, [](int u, int v) {return w[u] < w[v];});
        int last = 1;
        // int min_local = 1000000001;
        int min_index = ordh[1];
        int last_min_index = 0;
        for (int i = 1; i <= n + 1; i++) {
            // printf("i:%d %d %d %d %d\n", i, h[ordh[i]], h[ordh[last]], min_index, last_min_index);
            if (h[ordh[i]] != h[ordh[last]]) {
                for (int j = last; j < i; j++) {
                    minw[ordh[j]] = last_min_index;
                }
                last_min_index = min_index;
                if (w[ordh[i]] < w[min_index]) {
                    min_index = ordh[i];
                } 
                last = i;
            } else {
                if (w[ordh[i]] < w[min_index]) {
                    min_index = ordh[i];
                } 
            }
        }
        /* for (int i = 1; i <= n; i++) {
            printf("%d%c", minw[i], i == n ? '\n' : ' ');
        } */
        ans[ordh[1]] = -1;
        minw[ordh[1]] = 0;
        for (int i = 2; i <= n; i++) {
            if (w[ordh[i]] > w[minw[ordh[i]]] && minw[ordh[i]]) {
                ans[ordh[i]] = minw[ordh[i]];
            } else {
                ans[ordh[i]] = -1;
            }
            minw[ordh[i]] = 0;
        }

        for (int i = 1; i <= n; i++) {
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}