#include <bits/stdc++.h>
using namespace std;

constexpr int N = 50 + 10;
int T;
typedef long long ll;
char s[N];
int n, k;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &n, &k);
        scanf("%s", s + 1);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '*') {
                s[i] = 'x';
                ans++;
                break;
            }
        }
        for (int i = n; i; i--) {
            if (s[i] == '*') {
                s[i] = 'x';
                ans++;
                break;
            }
        }
        for (int i = 1; i <= n - k; i++) {
            if (s[i] == 'x') {
                bool ok = false;
                for (int j = i + 1; j <= i + k; j++) {
                    if (s[j] == 'x') {
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    for (int j = i + k; j > i; j--) {
                        if (s[j] == '*') {
                            s[j] = 'x';
                            ans++;
                            break;
                        }
                    }
                } 
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}