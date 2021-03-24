#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n, k;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            putchar('a' + i % 3);
        }
        puts("");
    }
    return 0;
}