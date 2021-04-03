#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n;
char a[N], b[N];
bool diff[N];
stack<int> s;

int main()
{
    for (scanf("%d", &T); T; T--)
    {
        while (!s.empty()) {
            s.pop();
        }
        scanf("%d", &n);
        scanf("%s", a + 1);
        scanf("%s", b + 1);
        for (int i = 1; i <= n; i++) {
            diff[i] = (a[i] == b[i]);
        }
        int n0 = 0, n1 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == '0') {
                n0++;
            } else {
                n1++;
            }
            if (n0 == n1) {
                s.push(i);
                // printf("%d ", i);
            }
        }
        // puts("");
        bool ok = true;
        int prev = 0;
        for (int i = n; i; i--) {
            if (a[i] == b[i]) {
                if (prev & 1) { // need to convert
                    while (!s.empty() && s.top() > i) {
                        s.pop();
                    }
                    if (s.empty() || s.top() != i) {
                        ok = false;
                        break;
                    }
                    prev++;
                } else {
                
                }
            } else {
                if (prev & 1) {
                    
                } else { // need to convert
                    while (!s.empty() && s.top() > i) {
                        s.pop();
                    }
                    if (s.empty() || s.top() != i) {
                        ok = false;
                        break;
                    }
                    prev++;
                }
            }
        }
        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}