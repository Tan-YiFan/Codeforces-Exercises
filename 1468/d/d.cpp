#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n, m, a, b;
int s[N];
priority_queue<int, vector<int>, greater<int> > q;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        while (!q.empty()) {
            q.pop();
        }
        scanf("%d %d %d %d", &n, &m, &a, &b);
        for (int i = 1; i <= m; i++) {
            scanf("%d", s + i);
            q.push(s[i]);
        }
        sort(s + 1, s + m + 1);
        int ans = 0;
        int lasting = (b > a) ? (b - 1) : (n - b);
        int start = 1;
        while (start <= m) {
            if (s[start] > lasting - 1) {
                break;
            }
            start++;
        }
        start--;
        // printf("start: %d\n", start);
        int cur = start;
        while (cur--) {
            if (s[cur] < lasting - ans - 1) {
                ans++;
            }
        }
        ans = min(ans, abs(b - a) - 1);
        printf("%d\n", ans);
    }
    return 0;
}