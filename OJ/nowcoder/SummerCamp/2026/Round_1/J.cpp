#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const string R = "23456789TJQKA", C = "CDHS";
const int P13[5] = {28561, 2197, 169, 13, 1};

void get(int c[], bool vis[])
{
    for (int i = 0; i < 4; i++) {
        string s; cin >> s;
        c[i] = R.find(s[0]) + C.find(s[1]) * 13;
        vis[c[i]] = true;
    }
}

int score(int cards[])
{
    int s = 0, cnt[60] = { 0 }, c[5];
    for (int i = 0; i < 5; i++) { 
        c[i] = cards[i];
        cnt[c[i] % 13]++;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (cnt[c[i] % 13] < cnt[c[j] % 13]) {
                swap(c[i], c[j]);
            } else if (cnt[c[i] % 13] == cnt[c[j] % 13]) {
                if (c[i] % 13 < c[j] % 13) swap(c[i], c[j]);
            }
        }
    }
    for (int i = 0; i < 5; i++) s += (c[i] % 13) * P13[i];
    int base = 400000;
    bool is_straight = (c[0] % 13 - c[4] % 13 == 4) || 
                       (c[0] % 13 == 12 && c[1] % 13 == 3 && c[4] % 13 == 0);
    bool is_flush = (c[0] / 13 == c[1] / 13 && 
                     c[1] / 13 == c[2] / 13 && 
                     c[2] / 13 == c[3] / 13 && 
                     c[3] / 13 == c[4] / 13);
    if (cnt[c[0] % 13] == 4) return s + base * 7;
    else if (cnt[c[0] % 13] == 3 && cnt[c[3] % 13] == 2) return s + base * 6; 
    else if (cnt[c[0] % 13] == 3) return s + base * 3;
    else if (cnt[c[0] % 13] == 2 && cnt[c[2] % 13] == 2) return s + base * 2;
    else if (cnt[c[0] % 13] == 2) return s + base * 1;
    else if (is_flush && is_straight) {
        // 顺子要考虑 A-5-4-3-2 的特殊情况
        // 顺子全部按照新的方式计数（顺子种类不多）
        if (c[0] % 13 == 12 && c[1] % 13 == 3) return 1 + base * 8; 
        return (c[0] % 13) + base * 8;  
    }
    else if (is_flush) return s + base * 5;
    else if (is_straight) {
        if (c[0] % 13 == 12 && c[1] % 13 == 3) return 1 + base * 4;
        return (c[0] % 13) + base * 4;
    }
    return s;
}

void solve()
{
    int c[5], p[5];
    bool vis[60] = { 0 };
    get(c, vis); get(p, vis);
    int cmax = 0, csub = 0, pmax = 0, prob = 0;
    for (int i = 0; i < 52; i++) {
        if (vis[i]) continue;
        c[4] = i; p[4] = i;
        int sc = score(c), sp = score(p);
        if (sc > cmax) {
            csub = cmax;
            cmax = sc;
            prob = sp;
        } else if (sc > csub) {
            csub = sc;
        }
        pmax = max(pmax, sp);
    }
    if (pmax > cmax || prob > csub) cout << "GeiWoCaPiXie\n";
    else if (pmax < cmax && prob < csub) cout << "WoYaoYanPai\n";
    else cout << "PaiMeiYouWenTi\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    cin >> _;
    while (_--) solve();
    
    return 0;
}