#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    int r, c;
    int p;
    vector<vector<long long>> mat;
    Matrix(int r, int c, int mod = 1) : r(r), c(c), p(mod), mat(r, vector<long long>(c, 0)) {}

    void build_identity() {
        assert(r == c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                mat[i][j] = (i == j ? 1 : 0);
            }
        }
    }

    Matrix operator*(const Matrix& other) const {
        assert(c == other.r);
        assert(p == other.p);
        Matrix res(r, other.c, p);
        for (int i = 0; i < r; ++i) {
            for (int k = 0; k < c; ++k) {
                long long tmp = mat[i][k];
                if (tmp == 0) continue;
                for (int j = 0; j < other.c; ++j) {
                    res.mat[i][j] = (res.mat[i][j] + tmp * other.mat[k][j]) % p;
                    if (res.mat[i][j] < 0) res.mat[i][j] += p;
                }
            }
        }
        return res;
    }

    Matrix operator^(long long n) const {
        assert(r == c);
        Matrix res(r, c, p);
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