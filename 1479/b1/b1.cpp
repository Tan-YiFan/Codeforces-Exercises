#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 3;
int T;
int n;
int a[N];
int p[N], q[N];
int p_len, q_len;
// int nxt[N];
queue<int> nxt[N];

int seg_count(int *arr, int len) {
    int ret = 0;
    for (int i = 1; i <= len; i++) {
        if (arr[i] != arr[i - 1]) {
            ret++;
        } 
        
    }
    return ret;
}

int next_index(int val) {
    if (nxt[val].empty()) {
        return 0x3f3f3f3f;
    } 
    return nxt[val].front();
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        nxt[a[i]].push(i);
    }
    for (int i = 1; i <= n; i++) {
        nxt[a[i]].pop();
        if (a[i] == p[p_len]) {
            q[++q_len] = a[i];
        } else if (a[i] == q[q_len]) {
            p[++p_len] = a[i];
        } else {
            if (next_index(p[p_len]) > next_index(q[q_len])) {
                q[++q_len] = a[i];
            } else {
                p[++p_len] = a[i];
            }
        }
    }
    cout << seg_count(p, p_len) + seg_count(q, q_len) << endl;
}