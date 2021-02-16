#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100 + 3;
int T;
int n;

int score[N][N];
int main()
{
    for (cin >> T; T; T--)
    {
        cin >> n;
        memset(score, 0, sizeof(score));
        int sum = ((n - 1) * n) >> 1;
        int win = 0, tie = 0;
        for (int i = sum - (sum % n); i >= 0; i -= n) {
            if (((sum - i) << 1) % n == 0) {
                win = i / n;
                tie = ((sum - i) << 1) / n;
                break;
            } 
        }
        for (int i = 1; i <= win; i++) {
            for (int j = 1; j <= n; j++) {
                int k = i + j;
                if (k > n) {
                    if (k % n == 0) {
                        k = n;
                    } else {
                        k = k % n;
                    }
                } 
                if (j < k) {
                    score[j][k] = 1;
                } else {
                    score[k][j] = -1;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                printf("%d%c", score[i][j], (i == n - 1 && j == n) ? '\n' : ' ');
            }
            
        }
        
    }
}