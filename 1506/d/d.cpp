#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int a[N];
int n;
priority_queue<int> q;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        while (!q.empty()) {
            q.pop();
        }
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        int mx = 1;
        int last = 1;
        sort(a + 1, a + n + 1);
        a[n + 1] = 0;
        
        for (int i = 2; i <= n + 1; i++) {
            if (a[i] == a[i - 1]) {
                
            } else {
                q.push(i - last);
                last = i;
            }
        }
        while (!q.empty()) {
            if (q.size() == 1) {
                break;
            } else {
                int i = q.top();
                q.pop();
                int j = q.top();
                q.pop();
                i--, j--, n -= 2;
                if (i > 0) {
                    q.push(i);
                }
                if (j > 0) {
                    q.push(j);
                } 
            }
        }
        printf("%d\n", n);
    }
    return 0;
}