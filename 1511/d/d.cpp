#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n, k;
int main()
{
	scanf("%d %d", &n, &k);
	int len = 0;
	while (len < n) {
		for (int i = 0; i < k; i++) {
			putchar('a' + i);
			len++;
			if (len == n) {
				break;
			}
			for (int j = i + 1; j < k; j++) {
				putchar('a' + i);
				len++;
				if (len == n) {
					break;
				}
				putchar('a' + j);
				len++;
				if (len == n) {
					break;
				}
			}
			if (len == n) {
				break;
			}
		}
	}
	
	puts("");
	return 0;
}