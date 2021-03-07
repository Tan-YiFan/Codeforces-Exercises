#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
typedef long long ll;
int n;
int a[N];
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        sort(a + 1, a + n + 1);
        ll alice = 0, bob = 0;
        for (int i = 1; i <= n; i++) {
            if (i & 1) { // Alice
                if (a[n + 1 - i] & 1) {
                    
                } else {
                    alice += a[n + 1 - i];
                }
            } else {
                if (a[n + 1 - i] & 1) {
                    bob += a[n + 1 - i];
                } else {
                    
                }
            }
        }

        if (alice < bob) {
            puts("Bob");
        } else if (alice == bob) {
            puts("Tie");
        } else {
            puts("Alice");
        }
    }
    return 0;
}