#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        putchar('9');
        if (n >= 2) {
            putchar('8');
        }
        if (n >= 3) {
            for (int i = 1; i <= n - 2; i++) {
                putchar((i + 8) % 10 + '0');
            }
        }
        putchar('\n');
    }
    return 0;
}