#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 3;
int T;
long long x;
// map<long long, bool> m;
set<long long> s;
vector<long long> v;
long long p[10001];

int bin_search(long long x)
{
    int lo = 1, hi = 10001;
    while (lo < hi - 1) {
        int mi = (lo + hi) >> 1;
        if (p[mi] == x) {
            return mi;
        } else if (p[mi] < x) {
            lo = mi;
        } else {
            hi = mi;
        }
    }
    return lo;
}

int main()
{
    for (long long i = 1; i <= 10000; i++) {
        p[i] = i * i * i;
    }
/*     for (long long i = 1; i <= 10000; i++) {
        // cout << i << endl;
        // long long k = i * i * i;
        for (long long j = i; j <= 10000; j++) {
            long long k = p[i] + p[j];
            if (k > 1000000000000) {
                break;
            } 
            // m[k] = true;
            // s.insert(k);
            v.push_back(k);
        }
    }
    cout << v.size() << endl;
    // cout << "sdfsdf" << endl;
    sort(v.begin(), v.end());
    cout << "sdfsdf" << endl; */
    for (cin >> T; T; T--)
    {
        cin >> x;
        // auto f = s.find(x);
        bool found = false;
        for (int i = 1; i <= 10000; i++) {
            int j = bin_search(x - p[i]);
            if (p[i] + p[j] == x) {
                found = true;
                break;
            } 
        }
        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}