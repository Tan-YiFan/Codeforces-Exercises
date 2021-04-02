#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int a, b;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &a, &b);
        a++, b++;
        printf("%d\n", (a - 1) * b + (b - 1) * a - a * b + 1);
    }
    return 0;
}