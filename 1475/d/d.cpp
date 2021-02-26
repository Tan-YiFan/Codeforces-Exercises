#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n, m;
priority_queue<int, vector<int>, less<int> > q1, q2;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (scanf("%d", &T); T; T--)
    {
        // cin >> n >> m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            // cin >> a[i];
            scanf("%d", a + i);
        }
        for (int i = 1; i <= n; i++) {
            int b;
            // cin >> b;
            scanf("%d", &b);
            if (b == 1) {
                q1.push(a[i]);
            } else {
                q2.push(a[i]);
            }
        }
        bool solved = false;
        int ans = 0;
        while (m > 0) {
            if (q1.empty() && q2.empty()) {
                break;
            } else if (q1.empty()) {
                m -= q2.top();
                ans += 2;
                q2.pop();
                if (m <= 0) {
                    solved = true;
                    break;
                } 
            } else if (q2.empty()) {
                m -= q1.top();
                ans += 1;
                q1.pop();
                if (m <= 0) {
                    solved = true;
                    break;
                } 
            } else {
                if (q1.size() == 1) {
                    if (q1.top() >= m) {
                        ans++;
                        q1.pop();
                        solved = true;
                        break;
                    } else {
                        m -= q2.top();
                        ans += 2;
                        q2.pop();
                        if (m <= 0) {
                            solved = true;
                            break;
                        }
                    }
                } else {
                    if (q1.top() >= m) {
                        ans++;
                        solved = true;
                        break;
                    }
                    int q1top = q1.top();
                    q1.pop();
                    if (q1.top() + q1top >= q2.top()) {
                        ans++;
                        m -= q1top;
                    } else {
                        ans += 2;
                        m -= q2.top();
                        q2.pop();
                        q1.push(q1top);
                    }
                }
            }
        }
        if (solved || !q1.empty() || !q2.empty()) {
            // cout << ans << endl;
            printf("%d\n", ans);
        } else {
            // cout << -1 << endl;
            puts("-1\n");
        }
        while (!q1.empty()) {
            q1.pop();
        }
        while (!q2.empty()) {
            q2.pop();
        }
    }
    return 0;
}