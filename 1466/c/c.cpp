#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
char s[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        int ans = 0;
        for (int i = 1; i < len; i++) {
            if (s[i] == s[i + 1] && s[i]) {
                ans++;
                s[i + 1] = 0;
            } else if (s[i - 1] == s[i + 1] && s[i - 1]) {
                ans++;
                s[i + 1] = 0;
            } 
        }
        printf("%d\n", ans);
    }
    return 0;
}