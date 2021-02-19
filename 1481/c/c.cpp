#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
int n, m;
int a[N], b[N], c[N];
vector<pair<int, int> > p;
bool color_in[N];
int ans[N];
// int ord[N];
vector<int> ord[N];
int main()
{
    for (cin >> T; T; T--)
    {
        cin >> n >> m;
        p.clear();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            color_in[a[i]] = true;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> c[i];
            // ord[c[i]] = i;
            ord[c[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) {
                p.push_back({ b[i], i }); // (colour, index)
            } 
        }
        if (p.empty()) {
            bool ok = false;
            if (color_in[c[m]]) {
                ok = true;
            } 
            if (!ok) {
                cout << "NO" << endl;
                // continue;
            } else {
                cout << "YES" << endl;
                int k = 0;
                for (int i = 1; i <= n; i++) {
                    if (c[m] == a[i]) {
                        k = i;
                        break;
                    } 
                }
                for (int i = 1; i <= m; i++) {
                    printf("%d%c", k, i == m ? '\n' : ' ');
                }
            }
        }
        else {
            bool ok = true;
            int x = 0; // index
            for (auto& i : p) {
                if (ord[i.first].size()) {
                    ans[ord[i.first].back()] = i.second;
                    ord[i.first].pop_back();
                    // ord[i] = 0;
                    x = i.second;
                } else {
                    ok = false;
                    break;
                }
            }
            if (ans[m] == 0) {
                for (int i = 1; i <= n; i++) {
                    if (b[i] == c[m]) {
                        ans[m] = i;
                    } 
                }
            } 
            if (ok && ans[m] != 0) {
                cout << "YES" << endl;
                for (int i = 1; i <= m; i++) {
                    printf("%d%c", ans[i] == 0 ? ans[m] : ans[i], i == m ? '\n' : ' ');
                }
            } else {
                cout << "NO" << endl;
            }
        }
        memset(ans, 0, (m + 3) << 2);
        memset(color_in, 0, (n + 3));
        // memset(ord, 0, (n + 3) << 2);
        for (int i = 1; i <= n; i++) {
            ord[i].clear();
        }
        memset(c, 0, (m + 3) << 2);
    }
}