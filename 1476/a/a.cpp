#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 3;
int T;

int main()
{
    for (cin >> T; T; T--)
    {
        int n, k;
        cin >> n >> k;
        // x * k = a * y + b * (y + 1) = ny + b
        if (n == k) {
            cout << 1 << endl;
        } else if (n < k) {
            if (k % n) {
                cout << (k / n) + 1 << endl;
            } else {
                cout << k / n << endl;
            }
        }
        else { // n > k
            if (n % k) {
                cout << 2 << endl;
            } else {
                cout << 1 << endl;
            }
        }
        
    }
}