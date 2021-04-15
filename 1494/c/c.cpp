#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n, m;
int a[N], b[N];
// pair<int, int> p[N];
// int plen;
// void initial(int lo, int hi)
// {
// 	plen = 0;
// 	p[++plen].first = lo;
// 	p[plen].second = lo;
// 	for (int i = lo + 1; i < hi; i++) {
// 		if (b[i] == b[i - 1] + 1) {
// 			p[plen].second++;
// 		} else {
// 			p[++plen].first = i;
// 			p[plen].second = i;
// 		}
// 	}
// }

// int no_move[N];
// void count_no_move_left(int lo, int hi)
// {
// 	no_move[lo - 1] = 0;
// 	int a_idx = lo, b_idx = 1;
// 	while (a_idx < hi && b_idx <= m) {
// 		if (a[a_idx] < b[b_idx]) {
// 			a_idx++;
// 			if (a_idx < hi)
// 				no_move[a_idx] = no_move[a_idx - 1];
// 		} else if (a[a_idx] > b[b_idx]) {
// 			b_idx++;
// 		} else {
// 			no_move[a_idx]++;
// 			a_idx++;
// 			b_idx++;
// 			if (a_idx < hi)
// 				no_move[a_idx] = no_move[a_idx - 1];
// 		}
// 	}
// /* 	for (int i = a_idx + 1; i < hi; i++) {
// 		no_move[i] = no_move[i - 1];
// 	} */
// }
// void count_no_move_right(int lo, int hi)
// {
// 	no_move[hi] = 0;
// 	int a_idx = hi - 1, b_idx = m;
// 	while (a_idx >= lo && b_idx >= 1) {
// 		if (a[a_idx] < b[b_idx]) {
// 			b_idx--;
// 		} else if (a[a_idx] > b[b_idx]) {
// 			a_idx--;
// 			if (a_idx >= lo)
// 				no_move[a_idx] = no_move[a_idx + 1];
// 		} else {
// 			no_move[a_idx]++;
// 			a_idx--;
// 			b_idx--;
// 			if (a_idx >= lo)
// 				no_move[a_idx] = no_move[a_idx + 1];
// 		}
// 	}
// /* 	for (int i = a_idx - 1; i >= lo; i--) {
// 		a[i] = a[i + 1];
// 	} */
// }
// int solve_left(int lo, int hi)
// {
// 	int ans = no_move[hi - 1];
// 	int cur_len = 1;
// 	int last = 0;
// 	int b_idx = 0;
// 	for (int i = m; i; i--) {
// 		if (b[i] > a[hi - 1]) {
// 			continue;
// 		}
// 		if (!b_idx) {
// 			b_idx = i;
// 		}
// 		if (last) {
// 			last--;
// 		} else {
// 			last = 0;
// 		}
// 		while (cur_len < hi - lo && a[hi - cur_len - 1] > b[i]) {
// 			cur_len++;
// 		}
// 		while (b_idx >= 1 && b[b_idx] >= b[i] - cur_len + 1) {
// 			b_idx--;
// 			last++;
// 		}
// 		ans = max(ans, last + no_move[hi - cur_len - 1]);
// 	}
// 	return ans;
// }
// int solve_right(int lo, int hi)
// {
// 	int ans = no_move[lo];
// 	int cur_len = 1;
// 	int last = 0;
// 	int b_idx = 0;
// 	for (int i = 1; i <= m; i++) {
// 		if (b[i] < a[lo]) {
// 			continue;
// 		}
// 		if (!b_idx) {
// 			b_idx = i;
// 		}
// 		if (last) {	
// 			last--;
// 		} else {
// 			last = 0;
// 		}
// 		while (cur_len < hi - lo && a[lo + cur_len] < b[i]) {
// 			cur_len++;
// 		}
// 		while (b_idx <= m && b[b_idx] <= b[i] + cur_len - 1) {
// 			b_idx++;
// 			last++;
// 		}
// 		ans = max(ans, last + no_move[lo + cur_len]);
// 	}
// 	return ans;
// }
// int main()
// {
// 	for (scanf("%d", &T); T; T--)
// 	{
// 		scanf("%d %d", &n, &m);
// 		for (int i = 1; i <= n; i++) {
// 			scanf("%d", a + i);
// 		}
// 		for (int i = 1; i <= m; i++) {
// 			scanf("%d", b + i);
// 		}
// 		initial(1, m + 1);
		
// 		int zero_a = n + 1;
// 		for (int i = 1; i <= n; i++) {
// 			if (a[i] >= 0) {
// 				zero_a = i;
// 				break;
// 			}
// 		}
// 		memset(no_move + 1, 0, n << 2);
// 		count_no_move_left(1, zero_a);
// 		count_no_move_right(zero_a, n + 1);
// 		/* for (int i = 1; i <= n; i++) {
// 			printf("%d%c", no_move[i], i == n ? '\n' : ' ');
// 		} */
// 		printf("%d\n", solve_left(1, zero_a) + solve_right(zero_a, n + 1));
// 	}
// 	return 0;
// }

int su[N];
int solve(const vector<int> &a, const vector<int> &b)
{
	int r = b.size() - 1;
	su[a.size()] = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		su[i] = su[i + 1];
		while (r >= 0 && b[r] > a[i]) {
			--r;
		}
		if (r >= 0 && b[r] == a[i]) {
			su[i]++;
		}
	}
	int ans = 0;
	int j = 0;
	r = 0;
	for (int i = 0; i < b.size(); i++) {
		while (j < a.size() && a[j] < b[i] + j) {
			j++;
		}
		while (r < b.size() && b[r] - b[i] < j) {
			r++;
		}
		ans = max(ans, r - i + su[j]);
	}
	return ans;
}
int main()
{
	for (scanf("%d", &T); T; --T) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d", b + i);
		}
		vector<int> al, bl, ar, br;
		for (int i = 1; i <= n; i++) {
			if (a[i] < 0) {
				al.push_back(-a[i]);
			} else {
				ar.push_back(a[i]);
			}
		}
		for (int i = 1; i <= m; i++) {
			if (b[i] < 0) {
				bl.push_back(-b[i]);
			} else {
				br.push_back(b[i]);
			}
		}
		reverse(al.begin(), al.end());
		reverse(bl.begin(), bl.end());
		printf("%d\n", solve(al, bl) + solve(ar, br));
	}
}

/* with reference */