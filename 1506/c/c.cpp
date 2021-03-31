#include <bits/stdc++.h>
using namespace std;

constexpr int N = 20 + 10;
int T;
typedef long long ll;
char a[N], b[N];
bool find_in_b(char *p, int len)
{
    bool ok = false;
    for (int i = 1; i <= strlen(b + 1) && b[i]; i++) {
        if (strncmp(b + i, p, len) == 0) {
            ok = true;
            break;
        }
    }
    return ok;
}
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%s", a + 1);
        scanf("%s", b + 1);
        int ans = 0;
        int start = 1, end = 1;
        int len = strlen(a + 1);
        while (start <= len && end <= len) {
            if (find_in_b(a + start, end - start + 1)) {
                ans = max(ans, end - start + 1);
                end++;
            } else {
                start++;
                end = max(end, start);
            }
        }
        int lenb = strlen(b + 1);
        // printf("ans:%d\n", ans);
        printf("%d\n", len + lenb - ans - ans);
    }
    return 0;
}