#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000 + 10;
int T;
typedef long long ll;
char r[N], b[N];
int n;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        scanf("%s", r + 1);
        scanf("%s", b + 1);
        int rw = 0, bw = 0;
        for (int i = 1; i <= n; i++) {
            if (r[i] > b[i]) {
                rw++;
            } else if (r[i] < b[i]) {
                bw++;
            }
        }
        if (rw > bw) {
            puts("RED");
        } else if (rw < bw) {
            puts("BLUE");
        } else {
            puts("EQUAL");
        }
    }
    return 0;
}