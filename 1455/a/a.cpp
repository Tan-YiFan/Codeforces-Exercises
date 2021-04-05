#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100 + 10;
int T;
typedef long long ll;
char s[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        printf("%d\n", n);
    }
    return 0;
}