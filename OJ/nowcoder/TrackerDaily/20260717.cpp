#include <bits/stdc++.h>
using namespace std;

int x[4], y[4];

bool Check(int a, int b, int c, int d) {
    int dx = x[b] - x[a];
    int dy = y[b] - y[a];
    return x[b] - x[c] == dy && y[c] - y[b] == dx
           && x[c] - x[d] == dx && y[c] - y[d] == dy;
}

bool Check() {
    return Check(0, 1, 2, 3) || Check(0, 1, 3, 2)
           || Check(0, 2, 1, 3) || Check(0, 2, 3, 1)
           || Check(0, 3, 1, 2) || Check(0, 3, 2, 1);
}

void Solve() {
    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
    }
    if (Check()) {
        cout << "wen";
        return;
    }
    for (int i = 0; i < 4; i++) {
        x[i]++;
        if (Check()) {
            cout << "hai xing";
            return;
        }
        x[i] -= 2;
        if (Check()) {
            cout << "hai xing";
            return;
        }
        x[i]++;
        y[i]++;
        if (Check()) {
            cout << "hai xing";
            return;
        }
        y[i] -= 2;
        if (Check()) {
            cout << "hai xing";
            return;
        }
        y[i]++;
    }
    cout << "wo jue de bu xing";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
}
