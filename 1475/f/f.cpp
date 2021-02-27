#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000 + 10;
int T;
typedef long long ll;
char a[N][N], b[N][N];
bool ba[N][N], bb[N][N];
int n;
bool testrow(int row)
{
    bool ret = true;
    for (int i = 1; i <= n; i++) {
        if (ba[row][i] != bb[row][i]) {
            ret = false;
            break;
        } 
    }
    if (ret) {
        return true;
    }
    ret = true;
    for (int i = 1; i <= n; i++) {
        if (ba[row][i] == bb[row][i]) {
            ret = false;
            break;
        } 
    }
    return ret;
}
bool testcol(int col)
{
    bool ret = true;
    for (int i = 1; i <= n; i++) {
        if (ba[i][col] != bb[i][col]) {
            ret = false;
            break;
        } 
    }
    if (ret) {
        return true;
    }
    ret = true;
    for (int i = 1; i <= n; i++) {
        if (ba[i][col] == bb[i][col]) {
            ret = false;
            break;
        } 
    }
    return ret;
}
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%s", a[i] + 1);
        }
        scanf("\n");
        for (int i = 1; i <= n; i++) {
            scanf("%s", b[i] + 1);
        }

        /* int diff = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] != b[i][j]) {
                    diff++;
                } 
            }
        }
        printf("%d\n", diff);
        if ((diff & 1) != (n & 1)) {
            puts("NO");
        } else {
            puts("YES");
        } */
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ba[i][j] = (a[i][j] == '1') ? true : false;
                bb[i][j] = (b[i][j] == '1') ? true : false;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (ba[i][1] != bb[i][1]) {
                for (int j = 1; j <= n; j++) {
                    ba[i][j] = !ba[i][j];
                }
            } 
        }
        bool ans = true;
        for (int i = 1; i <= n; i++) {
            if (!testcol(i)) {
                ans = false;
                break;
            } 
        }
        if (ans) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}