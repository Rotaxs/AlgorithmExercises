#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class DS
{
public:
    ll t1, t2;
    multiset<int> q1, q2;
    void clr()
    {
        q1.clear();
        q2.clear();
        t1 = t2 = 0;
    }
    void remake()
    {
        while (q1.size() > q2.size())
            q2.insert(*q1.rbegin()), t1 -= *q1.rbegin(), t2 += *q1.rbegin(), q1.erase(--q1.end());
        while (q1.size() < q2.size())
            q1.insert(*q2.begin()), t1 += *q2.begin(), t2 -= *q2.begin(), q2.erase(q2.begin());
    }
    void add(int x)
    {
        q1.insert(x);
        t1 += x;
        remake();
    }
    void del(int x)
    {
        if (q1.find(x) != q1.end())
            q1.erase(q1.lower_bound(x)), t1 -= x;
        else
            q2.erase(q2.lower_bound(x)), t2 -= x;
        remake();
    }
    ll qry()
    {
        if (q1.empty())
            return 0;
        if (q1.size() > q2.size())
            return (*q1.rbegin()) * 2;
        return *q1.rbegin() + *q2.begin();
    }
};