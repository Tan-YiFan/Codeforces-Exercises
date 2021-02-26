#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000 + 10;
int T;
typedef long long ll;
constexpr int MOD = 1000000000 + 7;
int n, k;
int a[N];
int num[N];
long long C[N][N]; // C(i, j), i >= j
void initial()
{
    for (int i = 1; i <= 1000; i++) {
        C[i][1] = i;
    }
    for (int i = 1; i <= 1000; i++) {
        C[i][i] = 1;
    }
    for (int i = 2; i <= 1000; i++) {
        C[i][i - 1] = i;
    }
    for (int i = 2; i <= 1000; i++) {
        for (int j = i + 1; j <= 1000; j++) {
            C[j][i] = (C[j - 1][i - 1] + C[j - 1][i]) % MOD;
        }
    }
}

int main()
{
    initial();
    for (cin >> T; T; T--)
    {
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            num[a[i]]++;
        }
        // sort(num + 1, num + n + 1, greater<int>());
        int ans = 1;
        // for (int i = 1; i <= n; i++) {
        //     printf("%d%c", num[i], i == n ? '\n' : ' ');
        // }
        for (int i = 1000; i; i--) {
            if (num[i] == 0) {
                continue;
            } else if (num[i] < k) {
                k -= num[i];
            } else {
                // cout << C[num[i]][k] << endl;
                ans = C[num[i]][k];
                break;
            }
        }
        cout << ans << endl;
        memset(a, 0, sizeof(a));
        memset(num, 0, sizeof(num));
    }
    return 0;
}