#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000 + 10;
int T;
int n;
int a[N];
int num[N], len;
int n1[N], n2[N], leng;
int front[N], back[N], backn2[N];
int main()
{
    for (cin >> T; T; T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for (int i = 1, last = 1; i <= n + 1; i++) {
            if (a[last] != a[i]) {
                num[++len] = i - last;
                last = i;
            } 
        }
        sort(num + 1, num + len + 1);
        for (int i = 1, last = 1; i <= len + 1; i++) {
            if (num[last] != num[i]) {
                n1[++leng] = num[last];
                n2[leng] = i - last;
                last = i;
            } 
        }
/*         for (int i = 1; i <= leng; i++) {
            printf("%d%c", n1[i], i == leng ? '\n' : ' ');
        }for (int i = 1; i <= leng; i++) {
            printf("%d%c", n2[i], i == leng ? '\n' : ' ');
        } */
        for (int i = 1; i <= leng; i++) {
            front[i] = front[i - 1] + n1[i] * n2[i];
        }
        for (int i = leng; i; i--) {
            backn2[i] = backn2[i + 1] + n2[i];
        }
        for (int i = leng; i; i--) {
            back[i] = back[i + 1] + (n1[i] - n1[i - 1]) * backn2[i];
        }
        /* for (int i = 1; i <= leng; i++) {
            printf("%d%c", front[i], i == leng ? '\n' : ' ');
        }
        for (int i = 1; i <= leng; i++) {
            printf("%d%c", back[i], i == leng ? '\n' : ' ');
        } */
        int ans = n + 1;
        for (int i = 1; i <= leng; i++) {
            if (front[i - 1] + back[i + 1] < ans) {
                ans = front[i - 1] + back[i + 1];
            } 
        }
        cout << ans << endl;
        memset(a, 0, (n + 3) << 2);
        
        memset(num, 0, (len + 3) << 2);
        len = 0;
        memset(front, 0, (leng + 3) << 2);
        memset(back, 0, (leng + 3) << 2);
        memset(backn2, 0, (leng + 3) << 2);
        memset(n1, 0, (leng + 3) << 2);
        memset(n2, 0, (leng + 3) << 2);
        leng = 0;
    }
}