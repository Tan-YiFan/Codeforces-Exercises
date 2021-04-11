#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n, a, b;
char s[N];
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		scanf("%d %d", &a, &b);
		scanf("%s", s + 1);
		n = a + b;
		s[n + 1] = '\0';
		bool ok = true;
		if (n & 1) {
			if (a & 1) {
				if (s[(n >> 1) + 1] == '1') {
					ok = false;
				}
				s[(n >> 1) + 1] = '0';
				a--;
			} else {
				if (s[(n >> 1) + 1] == '0') {
					ok = false;
				}
				s[(n >> 1) + 1] = '1';
				b--;
			}
			for (int i = 1; i <= (n >> 1); i++) {
				if (s[i] == '0' || s[n - i + 1] == '0') {
					if (s[i] == '1' || s[n - i + 1] == '1') {
						ok = false;
					}
					s[i] = s[n - i + 1] = '0';
					a -= 2;
				} else if (s[i] == '1' || s[n - i + 1] == '1') {
					if (s[i] == '0' || s[n - i + 1] == '0') {
						ok = false;
					}
					s[i] = s[n - i + 1] = '1';
					b -= 2;
				}
			}
			for (int i = 1; i <= (n >> 1); i++) {
				if (s[i] == '?') {
					if (a > 0) {
						s[i] = s[n - i + 1] = '0';
						a -= 2;
					} else {
						s[i] = s[n - i + 1] = '1';
						b -= 2;
					}
				}
			}
		} else {
			if (a & 1) {
				ok = false;
			}
			for (int i = 1; i <= (n >> 1); i++) {
				if (s[i] == '0' || s[n - i + 1] == '0') {
					if (s[i] == '1' || s[n - i + 1] == '1') {
						ok = false;
					}
					s[i] = s[n - i + 1] = '0';
					a -= 2;
				} else if (s[i] == '1' || s[n - i + 1] == '1') {
					if (s[i] == '0' || s[n - i + 1] == '0') {
						ok = false;
					}
					s[i] = s[n - i + 1] = '1';
					b -= 2;
				}
			}
			for (int i = 1; i <= (n >> 1); i++) {
				if (s[i] == '?') {
					if (a > 0) {
						s[i] = s[n - i + 1] = '0';
						a -= 2;
					} else {
						s[i] = s[n - i + 1] = '1';
						b -= 2;
					}
				}
			}
		}

		if (!ok || a || b) {
			puts("-1");
		} else {
			puts(s + 1);
		}
	}
	return 0;
}