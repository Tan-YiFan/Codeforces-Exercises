#include <bits/stdc++.h>
using namespace std;

constexpr int N = 50 + 3;
int T;
char s[N];
int main()
{
    for (cin >> T; T; T--)
    {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                if (s[i] == 'a') {
                    s[i] = 'b';
                } else {
                    s[i] = 'a';
                }
                
                
            } else {
                if (s[i] == 'z') {
                    s[i] = 'y';
                } else {
                    s[i] = 'z';
                }
                
                
            }
            
            
        }
        printf("%s\n", s + 1);
    }
}