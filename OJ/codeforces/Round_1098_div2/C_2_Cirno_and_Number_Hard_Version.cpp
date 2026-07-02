#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve()
{
    ull a; int n;
    cin >> a >> n;
    vector<int> D(n);
    for (int i = 0; i < n; i++) cin >> D[i];
    int d_min = D.front(), d_max = D.back();
    string S = to_string(a);
    int L = S.length();
    vector<ull> cands;
    if (d_min == 0) cands.push_back(0);

    auto add_cand = [&](string s)
    {
        if (s.empty()) return;
        if (s.length() > 1 && s[0] == '0') return;
        cands.push_back(stoull(s));
    };

    // 位数比 a 少一位
    if (L > 1)
    {
        string s(L - 1, d_max + '0');
        add_cand(s);
    }
    // 位数比 a 多一位
    int nz_min = -1;
    for (int d : D)
    {
        if (d > 0)
        {
            nz_min = d;
            break;
        }
    }
    if (nz_min != -1)
    {
        string s = "";
        s += (char)(nz_min + '0');
        s.append(L, d_min + '0');
        add_cand(s);
    }
    // 位数和 a 相同
    string prefix = "";
    bool match_possible = true;
    for (int i = 0; i < L; i++)
    {
        int req = S[i] - '0';
        // 找比当前位大的第一个数，后面全填最小值
        int up_c = -1;
        for (int d : D)
        {
            if (d > req)
            {
                up_c = d;
                break;
            }
        }
        if (up_c != -1)
        {
            string s = prefix + (char)(up_c + '0') + string(L - 1 - i, d_min + '0');
            add_cand(s);
        }
        // 找比当前位小的第一个数，后面全填最大值
        int down_c = -1;
        for (int j = n - 1; j >= 0; j--)
        {
            if (D[j] < req)
            {
                down_c = D[j];
                break;
            }
        }
        if (down_c != -1)
        {
            string s = prefix + (char)(down_c + '0') + string(L - 1 - i, d_max + '0');
            add_cand(s);
        }
        // 找和当前位相同的数
        bool found = false;
        for (int d : D)
        {
            if (d == req)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            prefix += (char)(req + '0');
        }
        else
        {
            match_possible = false;
            break;
        }
    }
    if (match_possible) add_cand(prefix);

    ull ans = ULLONG_MAX;
    for (ull c : cands)
    {
        ull diff = a > c ? a - c : c - a;
        ans = min(ans, diff);
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}