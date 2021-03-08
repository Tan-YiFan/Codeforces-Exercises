#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
int reflect[10];
int H, M;
void initial()
{
    reflect[0] = 0;
    reflect[1] = 1;
    reflect[2] = 5;
    reflect[3] = -1;
    reflect[4] = -1;
    reflect[5] = 2;
    reflect[6] = -1;
    reflect[7] = -1;
    reflect[8] = 8;
    reflect[9] = -1;
}
class Mytime {
public:
    int h, m;
    Mytime(int _h, int _m) { h = _h, m = _m; }
    Mytime() { }
    bool valid() {
        Mytime temp = *this;
        int a, b, c, d;
        a = h / 10;
        b = h % 10;
        c = m / 10;
        d = m % 10;

        if (reflect[h % 10] == -1) {
            *this = temp;
            return false;
        }
        h /= 10;
        if (reflect[h % 10] == -1) {
            *this = temp;
            return false;
        }
        if (reflect[m % 10] == -1) {
            *this = temp;
            return false;
        }
        m /= 10;
        if (reflect[m % 10] == -1) {
            *this = temp;
            return false;
        }
        if (10 * reflect[d] + reflect[c] >= H || 10 * reflect[b] + reflect[a] >= M) {
            *this = temp;
            return false;
        }
        *this = temp;
        return true;
    }
    void incr() {
        m++;
        if (m / M == 1) {
            m -= M;
            h++;
        }
        if (h / H == 1) {
            h -= H;
        }
    }
};
int main()
{
    initial();
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d", &H, &M);
        Mytime t;
        scanf("%d:%d", &t.h, &t.m);
        // printf("%02d:%02d\n", t.h, t.m);
        
        while (!t.valid()) {
            t.incr();
        // printf("%02d:%02d\n", t.h, t.m);
            
        }
        printf("%02d:%02d\n", t.h, t.m);
    }
    return 0;
}