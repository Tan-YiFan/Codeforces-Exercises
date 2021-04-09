#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
char s[N];
int n;
int surf_num[N];
bool del[N];
bool exist[26];
bool surf_index[N][26];
bool surf[26];

int get_surf(int i)
{
	int ret = 0;
	for (int j = 0; j < 26; j++) {
		if (surf_index[i][j] && !exist[j]) {
			ret++;
		}
	}
	return ret;
}

int main()
{
	for (scanf("%d", &T); T; T--)
	{
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for (int i = 1; i <= n; i++) {
			s[i] -= 'a';
			del[i] = false;
			
			surf_num[i] = 0;
			for (int j = 0; j < 26; j++) {
				surf_index[i][j] = false;
			}
		}
		for (int i = 0; i < 26; i++) {
			surf[i] = false;
			exist[i] = false;
		}
		for (int i = n; i; i--) {
			surf[s[i]] = true;
			for (int j = 0; j < 26; j++) {
				surf_index[i][j] = surf[j];
			}
		}

		int lo = 1, hi = 1;
		char mx = 0;
		for (int i = 1; i <= n; i++) {
			if (exist[s[i]]) {
				del[i] = true;
			}
			if (get_surf(i) != get_surf(i + 1)) {
				
				hi = i;
				if (mx >= s[i]) {
					for (int j = lo; j < hi; j++) {
						if (mx == s[j]) {
							exist[s[j]] = true;
							i = j;
							hi = lo = i + 1;
							mx = 0;
							continue;
						} else {
							del[j] = true;
						}
					}
				}
				bool found = false;
				for (int j = lo; j < hi; j++) {
					if (!found && mx != s[j]) {
						del[j] = true;
					} else {
						found = true;
						if (s[j] > s[i] && !exist[s[j]]) {
							exist[s[j]] = true;
						} else {
							del[j] = true;
						}
					}
				}
				exist[s[i]] = true;
				hi = lo = i + 1;
				mx = 0;
			} else if (!exist[s[i]]) {
				mx = max(mx, s[i]);
				hi++;
			}
		}
		/* for (int i = lo; i < hi; i++) {
			del[i] = true;
		} */
		/* if (T == 10000 - 802 + 1) {
			for (int i = 1; i <= n; i++) {
				putchar(s[i] + 'a');
			}
			puts("");
		} */
		for (int i = 1; i <= n; i++) {
			if (!del[i]) {
				putchar(s[i] + 'a');
			}
		}
		
		puts("");
		for (int i = 0; i < 26; i++) {
			exist[i] = false;
			surf[i] = false;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 26; j++) {
				surf_index[i][j] = false;
			}
			del[i] = false;
		}
	}
	return 0;
}