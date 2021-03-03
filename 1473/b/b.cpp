#include <bits/stdc++.h>
using namespace std;

constexpr int N = 20 + 10;
int T;
typedef long long ll;
char s[N], t[N];
char s1[N * N], t1[N * N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%s", s);
        scanf("%s", t);
        memset(s1, 0, sizeof(s1));
        memset(t1, 0, sizeof(t1));
        int s_len = strlen(s), t_len = strlen(t);
        int lcm = s_len * t_len / __gcd(s_len, t_len);
        for (int i = 1; i <= lcm / s_len; i++) {
            strcat(s1, s);
        }
        for (int i = 1; i <= lcm / t_len; i++) {
            strcat(t1, t);
        }
        if (strcmp(s1, t1)) {
            puts("-1");
        } else {
            puts(s1);
        }
    }
    return 0;
}