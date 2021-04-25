#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 10;
int T;
typedef long long ll;
mt19937 rn(chrono::steady_clock::now().time_since_epoch().count());
int n;
char a[N << 1], b[N << 1], c[N << 1];
char ans[N << 2];
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		cin >> n;
		scanf("%s", a);
		scanf("%s", b);
		scanf("%s", c);
		char *pa = a, *pb = b, *pc = c, *p = ans;
		int n1 = n << 1;
		int n2 = n * 3;
		while (pa != a + n1 && pb != b + n1 && pc != c + n1) {
			if (*pa == *pb && *pb == *pc) {
				*p = *pa;
				p++, pa++, pb++, pc++;
			} else if (*pa == *pb) {
				*p = *pa;
				p++, pa++, pb++;
			} else if (*pb == *pc) {
				*p = *pc;
				p++, pb++, pc++;
			} else {
				*p = *pa;
				p++, pa++, pc++;
			}
		}
		if (pa == a + n1) {
			if (pb != b + n1 && pc != c + n1) {
				if (pb - b > pc - c) {
					memcpy(p, pb, b + n1 - pb);
					p += b + n1 - pb;
				} else {
					memcpy(p, pc, c + n1 - pc);
					p += c + n1 - pc;
				}
			}
		} else if (pb == b + n1) {
			if (pc != c + n1) {
				if (pa - a > pc - c) {
					memcpy(p, pa, a + n1 - pa);
					p += a + n1 - pa;
				} else {
					memcpy(p, pc, c + n1 - pc);
					p += c + n1 - pc;
				}
			}
		} else { // only pc == c + n1
			if (pa - a > pb - b) {
				memcpy(p, pa, a + n1 - pa);
				p += a + n1 - pa;
			} else {
				memcpy(p, pb, b + n1 - pb);
				p += b + n1 - pb;
			}
		}
		memset(p, '0', ans + n2 - p);
		ans[n2] = '\0';
		puts(ans);
	}
	return 0;
}