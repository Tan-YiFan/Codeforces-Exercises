#include <bits/stdc++.h>
using namespace std;

constexpr int N = 50 + 10;
int T;
typedef long long ll;
char a[N];
bool is_left = true;
int len;
char c;
void initial()
{
    if (a[0] == c) {
        is_left = true;
    } else {
        is_left = false;
    }
}

bool solve()
{
    int sz = 0;
    for (int i = 0; i < len; i++) {
        if (is_left) {
            if (a[i] == c) {
                sz++;
            } else {
                if (sz == 0) {
                    return false;
                }
                sz--;
            }
        } else {
            if (a[i] == c) {
                if (sz == 0) {
                    return false;
                }
                sz--;
            } else {
                sz++;
            }
        }
    }
    if (sz) {
        return false;
    } 
    return true;
}
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        int num[3] = { 0, 0, 0 };
        scanf("%s", a);
        len = strlen(a);
        for (int i = 0; i < len; i++) {
            num[a[i] - 'A']++;
        }
        if (num[0] == num[1] + num[2]) {
            c = 'A';
            initial();
            if (solve()) {
                puts("YES");
            } else {
                puts("NO");
            }
        } else if (num[1] == num[0] + num[2]) {
            c = 'B';
            initial();
            if (solve()) {
                puts("YES");
            } else {
                puts("NO");
            }
        } else if (num[2] == num[0] + num[1]) {
            c = 'C';
            initial();
            if (solve()) {
                puts("YES");
            } else {
                puts("NO");
            }
        } else {
            puts("NO");
        }
    }
    return 0;
}