#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5000 + 10;
int T;
typedef long long ll;
char s[N];
int x[N], y[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%s", s + 1);
        int sz = 0;
        int len = strlen(s + 1);
        int x_cur = 0, y_cur = 0;
        for (int i = 1; i <= len; i++) {
            switch (s[i]) {
            case 'L':
                x_cur--;
                break;
            case 'R':
                x_cur++;
                break;
            case 'D':
                y_cur--;
                break;
            case 'U':
                y_cur++;
                break;
            default:
                ;
            }
            x[++sz] = x_cur;
            y[sz] = y_cur;
        }
        /* for (int i = 1; i <= len; i++) {
            printf("loc: %d %d\n", x[i], y[i]);
        } */
        bool ans = false;
        for (int i = 1; i <= len; i++) {
            int x_test = 0, y_test = 0;
            for (int j = 1; j <= len; j++) {
                int x_nxt = x_test, y_nxt = y_test;
                switch (s[j]) {
                case 'L':
                    x_nxt--;
                    break;
                case 'R':
                    x_nxt++;
                    break;
                case 'D':
                    y_nxt--;
                    break;
                case 'U':
                    y_nxt++;
                    break;
                default:
                    ;
                }
                if (x_nxt != x[i] || y_nxt != y[i]) {
                    x_test = x_nxt;
                    y_test = y_nxt;
                } 
            }
            if (!x_test && !y_test) {
                printf("%d %d\n", x[i], y[i]);
                ans = true;
                break;
            } 
        }
        if (!ans) {
            puts("0 0");
        } 
    }
    return 0;
}