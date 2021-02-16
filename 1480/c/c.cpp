#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000 + 3;
int T;
int hi, lo, mi;
int v[N];

void get(int index) {
    if (v[index] == 0) {
        cout << "? " << index << endl;
        cin >> v[index];
        cout.flush();
    } 
    
}

int main()
{
    int n;
    cin >> n;
    lo = 1;
    hi = n;
    mi = (lo + hi) >> 1;
/*     get(lo), get(hi), get(mi);
    int i = 0;
    while (lo < hi && i < 100) {
        i++;
        if (v[lo] < v[mi]) {
            if (v[mi] < v[hi]) { // lo < mi < hi
                hi = mi - 1;
                mi = (lo + hi) >> 1;
                get(mi);
            } else if (v[lo] < v[hi]) { // lo < hi < mi
                lo = mi + 1;
                mi = (lo + hi) >> 1;
                get(mi);
            } else { // hi < lo < mi
                lo = mi + 1;
                mi = (lo + hi) >> 1;
                get(mi);
            }
        } else {
            if (v[mi] < v[hi]) { // mi < lo, mi < hi 
                // hi = mi;
                // mi = (lo + hi) >> 1;
                lo = (lo + mi) >> 1;
                hi = (hi + mi) >> 1;
                get(lo), get(hi);
            } else {
                lo = mi + 1;
                mi = (lo + hi) >> 1;
                get(mi);
            }
        }
    } */
    while (lo < hi) {
        get(mi);
        get(mi + 1);
        if (v[mi] > v[mi + 1]) {
            lo = mi + 1;
            mi = (lo + hi) >> 1;
        } else {
            hi = mi;
            mi = (lo + hi) >> 1;
        }
    }
    
    cout << "! " << lo << endl;
}