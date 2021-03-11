#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000 + 10;
int T;
typedef long long ll;
char s[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        bool ans = true;
        if (n & 1) {
            ans = false;
        }
        if (s[1] == ')' || s[n] == '(') {
            ans = false;
        } 
        if (ans) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}