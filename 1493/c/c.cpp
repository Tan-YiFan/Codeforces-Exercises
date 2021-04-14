#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n, k;
char s[N];
int cnt[26];
int temp[26];
int missing, change;
bool test_ok(int loc)
{
	
	for (int i = 0; i < 26; i++) {
		temp[i] = cnt[i];
	}
	/* if (loc <= n) {
		temp[s[loc] - 'a']--;
	} */
/* 	for (int i = loc; i <= n; i++) {
		temp[s[i] - 'a']--;
	} */
	for (int i = 0; i < 26; i++) {
		temp[i] %= k;
	}
	missing = 0;
	for (int i = 0; i < 26; i++) {
		missing += (k - temp[i]) % k;
	}
	change = n - loc + 1;
	if ((missing > change) || ((change - missing) % k)) {
		return false;
	} else {
		if (loc == n + 1) {
			return true;
		}
		if (missing == change) {
			for (int i = s[loc] - 'a' + 1; i < 26; i++) {
				if (temp[i]) {
					return true;
				}
			}
		} else {
			if (s[loc] == 'z') {
				return false;
			}
			return true;
		}
		// return true;
		return false;
	}
}
int main()
{
	for (scanf("%d", &T); T; T--)
	{
		scanf("%d %d", &n, &k);
		scanf("%s", s + 1);
		if (n % k) {
			puts("-1");
			continue;
		}
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			cnt[s[i] - 'a']++;
		}
		if (test_ok(n + 1)) {
			puts(s + 1);
			continue;
		}
		
		for (int i = n; i; i--) {
			cnt[s[i] - 'a']--;
			if (test_ok(i)) {
				/* for (int j = i; j <= n; j++) {
					cnt[s[j] - 'a']--;
				} */
				/* for (int j = 0; j < 26; j++) {
					cnt[j] %= k;
				} */
				// cnt[s[i] - 'a']--;
				if (missing == change) {
					for (int l = s[i] - 'a' + 1; l < 26; l++) {
						if (cnt[l] % k) {
							s[i] = l + 'a';
							cnt[s[i] - 'a']++;
							break;
						}
					}
				} else {
					s[i]++;
					cnt[s[i] - 'a']++;
					// s[i]++;
				}
				
				for (int j = n; j > i; j--) {
					bool ok = false;
					for (int l = 25; l >= 0; l--) {
						if (cnt[l] % k) {
							s[j] = l + 'a';
							cnt[l]++;
							ok = true;
							break;
						}
					}
					if (!ok) {
						s[j] = 'a';
					}
				}
				break;
			}
		}
		puts(s + 1);
	}
	return 0;
}