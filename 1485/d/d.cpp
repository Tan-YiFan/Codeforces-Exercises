#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500 + 3;
int T;
int a[N][N];

// reference
int gcd(int x, int y) {
    if (x < y) {
        swap(x, y);
    } 
    if (y == 0) {
        return x;
    } 
    if (y == 1) {
        return 1;
    } 
    return gcd(x % y, y);
}

int initial() {
    int ans = 1;
    for (int i = 1; i <= 16; i++) {
        ans = ans * i / gcd(ans, i);
    }
    
    return ans;
}

int power4(int x) {
    int y = x * x;
    return y * y;
}

int main()
{
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            cin >> a[i][j];
        }
        
    }
    int ans = initial();
    // cout << ans << endl;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if ((i + j) & 1) {
                cout << ans;
            } else {
                cout << ans + power4(a[i][j]);
            }
            if (j < y) {
                cout << ' ';
            } else {
                cout << endl;
            }
            
            
            
        }
        
    }
    
}