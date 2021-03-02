#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;

bool is_prime(int num)
{
    int j = sqrt(num);
    for (int i = 2; i <= j; i++) {
        if ((num % i) == 0) {
            return false;
        } 
    }
    return true;
}

int len;
int prime[N];
void initial1()
{
    for (int i = 2; i <= 40000; i++) {
        if (is_prime(i)) {
            prime[++len] = i;
        } 
    }
}

int ans[N];
int search(int num) {
    for (int i = 1; i <= len; i++) {
        if (prime[i] >= num) {
            return prime[i];
        } 
    }
    return -1;
}
void initial2()
{
    for (int i = 1; i <= 10000; i++) {
        int d1 = search(1 + i);
        int d2 = search(d1 + i);
        ans[i] = d1 * d2;
    }
}
int d;
int main()
{
    initial1();
    initial2();
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d", &d);
        printf("%d\n", ans[d]);
    }
    return 0;
}