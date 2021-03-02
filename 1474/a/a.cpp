#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int n;
// char b[N];
// char ans[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d\n", &n);
        int last = 0;
        for (int i = 1; i <= n; i++) {
            char b = getchar();
            if (last == 0) {
                putchar('1');
                last = 1 + b - '0';
            } else if (last == 1) {
                if (b == '1') {
                    last = 2;
                    putchar('1');
                } else {
                    last = 0;
                    putchar('0');
                }
            } else if (last == 2) {
                last = 1;
                if (b == '1') {
                    putchar('0');
                } else {
                    putchar('1');
                }
            } 
        }
        getchar();
        putchar('\n');
    }
    return 0;
}