#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int a[N];
int n, q;
int main()
{
    for (T = 1; T; T--)
    {
        scanf("%d %d", &n, &q);
        int num = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            if (a[i]) {
                num++;
            } 
        }
        int t, x;
        for (int i = 1; i <= q; i++) {
            scanf("%d %d", &t, &x);
            switch (t) {
            case 1:
                if (a[x]) {
                    num--;
                } else {
                    num++;
                }
                a[x] = 1 - a[x];
                break;
            case 2:
                if (num >= x) {
                    puts("1");
                } else {
                    puts("0");
                }
                break;
            default:
                ;
            }
            
        }
        
    }
    return 0;
}