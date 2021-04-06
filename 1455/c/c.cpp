#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int x, y;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &x, &y);
        printf("%d %d\n", x - 1, y);
    }
    return 0;
}