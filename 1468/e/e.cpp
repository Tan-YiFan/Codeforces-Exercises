#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int a[4];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        for (int i = 0; i < 4; i++) {
            scanf("%d", a + i);
        }
        sort(a, a + 4);
        printf("%d\n", a[0] * a[2]);
    }
    return 0;
}