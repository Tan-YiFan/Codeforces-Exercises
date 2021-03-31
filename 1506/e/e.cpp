#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int a[N];
int n;
deque<int> dq;
bool exist[N];
int ans[N];
stack<int> s;

int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        for (int i = 1; i <= n; i++) {
            dq.push_back(i);
            exist[i] = false;
        }

        for (int i = 1; i <= n; i++) {
            if (a[i] != a[i - 1]) {
                ans[i] = a[i];
                exist[a[i]] = true;
            } else {
                while (exist[dq.front()]) {
                    dq.pop_front();
                }
                ans[i] = dq.front();
                exist[dq.front()] = true;
                dq.pop_front();
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
        }
        while (!dq.empty()) {
            dq.pop_back();
        }
        for (int i = 1; i <= n; i++) {
            exist[i] = false;
        }
        int last = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != a[i - 1]) {
                ans[i] = a[i];
                exist[ans[i]] = true;
                if (last != 0) {
                    s.push(last);
                } 
                last = a[i] - 1;
            } else {
                while (exist[last]) {
                    last = s.top();
                    s.pop();
                }
                ans[i] = last;
                exist[ans[i]] = true;
                last--;
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
        }

    }
    return 0;
}