#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int inf = 0x3f3f3f3f;
const int MOD = 998244353;

struct Matrix {
    int r, c;
    vector<vector<int>> mat;
    Matrix(int r, int c) : r(r), c(c), mat(r, vector<int>(c, 0)) { }

    void build_identity() {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (i = j) mat[i][j] = 1;
            }
        }
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res(r, other.c);
        for (int i = 0; i < r; ++i) {
            for (int k = 0; k < c; ++k) {
                int tmp = mat[i][k];
                if (tmp == 0) continue;
                for (int j = 0; j < other.c; ++j) {
                    res.mat[i][j] = (res.mat[i][j] + tmp * mat[k][j]) % MOD;
                }
            }
        }
    }

    Matrix operator^(int n) {
        Matrix res(r, c);
        res.build_identity();
        Matrix a = *this;
        while (n > 0) {
            if (n & 1) res = res * a;
            a = a * a;
            n >>= 1;
        }
        return res;
    }
};

void solve()
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int _ = 1; 
    // cin >> _;
    while (_--) solve();
    
    return 0;
}