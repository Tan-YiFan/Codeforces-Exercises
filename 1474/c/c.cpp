#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2000 + 10;
int T;
typedef long long ll;
int a[N];
int n;
bool selected[N];
int len;
int ans1[N], ans2[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        // memset(selected, 0, sizeof(selected));
        n <<= 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        
        sort(a + 1, a + n + 1);
        bool success = false;
        int selectedidx = 1;
        for (; selectedidx < n; selectedidx++) {
            len = 0;
            memset(selected, 0, sizeof(selected));
            selected[n] = true;
            selected[selectedidx] = true;
            int last = n;
            int cnt = 2;
            ans1[++len] = n;
            ans2[len] = selectedidx;
            while (cnt < n) {
                int nxt = last - 1;
                while (selected[nxt]) {
                    nxt--;
                }
                int i = 1;
                for (i = 1; i < nxt; i++) {
                    if (!selected[i] && (a[i] + a[nxt] == a[last])) {
                        break;
                    } 
                }
                if (i == nxt) {
                    break;
                }
                ans1[++len] = i;
                ans2[len] = nxt;
                selected[i] = true;
                selected[nxt] = true;
                last = nxt;
                cnt += 2;
            }
            if (cnt == n) {
                success = true;
                break;
            } 
        }
        if (success) {
            puts("YES");
            printf("%d\n", a[n] + a[selectedidx]);
            for (int i = 1; i <= len; i++) {
                printf("%d %d\n", a[ans1[i]], a[ans2[i]]);
            }
        } else {
            puts("NO");
        }
    }
    return 0;
}