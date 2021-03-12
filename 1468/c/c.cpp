#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500000 + 10;
int T;
typedef long long ll;
class customer {
public:
    int id;
    int spend;
    
};
int cost[N];
bool operator< (const customer& l, const customer& r) {
    if (l.spend != r.spend) {
        return l.spend < r.spend;
    }
    return l.id > r.id;
}
bool operator== (const customer& l, const customer& r) {
    return l.id == r.id && l.spend == r.spend;
}
class cmp {
public:
    bool operator()(const customer& l, const customer& r) {
        return l < r;
    }
};
set<int> beginner;
set<customer, cmp> expert;
int len;
int main()
{
    for (scanf("%d", &T); T; T--)
    {
        int temp;
        scanf("%d", &temp);
        int pick;
        customer pick2;
        switch (temp) {
        case 1:
            scanf("%d", &pick);
            beginner.insert(++len);
            expert.insert(customer{ len, pick });
            cost[len] = pick;
            break;
        case 2:
            assert(beginner.size());
            assert(expert.size());
            pick = *beginner.begin();
            printf("%d%c", pick, T == 1 ? '\n' : ' ');
            beginner.erase(beginner.begin());
            expert.erase(expert.find(customer{ pick, cost[pick] }));
            break;
        case 3:
            assert(beginner.size());
            assert(expert.size());
            pick2 = *(--expert.end());
            printf("%d%c", pick2.id, T == 1 ? '\n' : ' ');
            beginner.erase(beginner.find(pick2.id));
            expert.erase(--expert.end());
            break;
        default:
            ;
        }
        
    }
    return 0;
}