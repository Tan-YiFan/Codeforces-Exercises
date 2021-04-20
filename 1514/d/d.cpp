#include <bits/stdc++.h>
using namespace std;

constexpr int N = 300000 + 10;
int T;
typedef long long ll;
int n, q;
int a[N];
int l[N], r[N];
vector<int> num[N];
mt19937 rn(chrono::steady_clock::now().time_since_epoch().count());
void solve_random()
{
	// mt19937 rn(chrono::steady_clock::now().time_since_epoch().count());
	for (int i = 1; i <= n; i++) {
		num[a[i]].push_back(i);
	}
	for (int i = 1; i <= q; i++) {
		int f = 0;
		int m = r[i] - l[i] + 1;
		// map<int, bool> exist;
		srand(time(NULL));
		for (int _ = 1; _ <= 41; _++) {
			// int idx = l[i] + rand() % m;
			int idx = uniform_int_distribution<int>(l[i], r[i])(rn);
			f = upper_bound(num[a[idx]].begin(), num[a[idx]].end(), r[i]) - lower_bound(num[a[idx]].begin(), num[a[idx]].end(), l[i]);
			if (f > ((m + 1) >> 1)) {
				break;
			}
		}
		if (f > (m + 1) / 2) {
			// printf("%d\n", f * 2 - m);
			cout << f * 2 - m << endl;
		} else {
			// puts("1");
			cout << 1 << endl;
		}
	}
}

int tree[N << 2];

int cnt(int l, int r, int c)
{
	return upper_bound(num[c].begin(), num[c].end(), r) - lower_bound(num[c].begin(), num[c].end(), l);
}

int query(int node, int st, int en, int l, int r)
{
	if (en < l || st > r || r < l) {
		return 0;
	}
	if (l <= st && en <= r) {
		return cnt(l, r, tree[node]);
	}
	int mid = (st + en) >> 1;
	return max(query(node << 1, st, mid, l, r), query(1 + (node << 1), mid + 1, en, l, r));
}

void build(int node, int st, int en)
{
	if (st == en) {
		tree[node] = a[st];
	} else {
		int mid = (st + en) >> 1;
		build(node * 2, st, mid);
		build(1 + (node * 2), mid + 1, en);
		tree[node] = (cnt(st, en, tree[node * 2]) > cnt(st, en, tree[1 + (node * 2)])) ? tree[node * 2] : tree[1 + (node * 2)];
	}
}

void solve()
{
	for (int i = 1; i <= n; i++) {
		num[a[i]].push_back(i);
	}
	build(1, 1, n);
	for (int i = 1; i <= q; i++) {
		cout << max(1, (query(1, 1, n, l[i], r[i]) * 2) - (r[i] - l[i] + 1)) << endl;;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];;
	}
	for (int i = 1; i <= q; i++) {
		cin >> l[i] >> r[i];
	}
	// solve_random();
	solve();

	return 0;
}