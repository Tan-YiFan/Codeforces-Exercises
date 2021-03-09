#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int u, v;

// reference
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &u, &v);
        if (u > v) {
            puts("NO");
            continue;
        }
        bool ans = true;
        vector<int> a, b;
        for (int i = 0; i <= 30; i++) {
            if (u & 1) {
                a.push_back(i);
            }
            if (v & 1) {
                b.push_back(i);
            }
            u >>= 1, v >>= 1;
        }
        if (a.size() < b.size()) {
            ans = false;
        } else {
            for (int i = 0; i < b.size(); i++) {                
                if (a[i] > b[i]) {
                    ans = false;
                    break;
                } 
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