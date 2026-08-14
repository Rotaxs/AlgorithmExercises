#include "stdlib.h"
#include "stdio.h"

const int MOD = 1e9 + 7;

struct Matrix {
    int r, c;
    int **mat;
};

struct Matrix* create_matrix(int r, int c) {
    struct Matrix *m = (struct Matrix*)malloc(sizeof(struct Matrix));
    m->r = r; m->c = c;
    m->mat = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        m->mat[i] = (int*)calloc(c, sizeof(int));
    }
    return m;
}

void set_matrix(struct Matrix* m, int *mat) {
    for (int i = 0; i < m->r; ++i) {
        for (int j = 0; j < m->c; ++j) {
            m->mat[i][j] = mat[i * m->c + j];
        }
    }
}

void free_matrix(struct Matrix* m) {
    if (!m) return;
    for (int i = 0; i < m->r; ++i) {
        free(m->mat[i]);
    }
    free(m->mat);
    free(m);
}

void build_identity(struct Matrix *m) {
    int r = m->r, c = m->c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            m->mat[i][j] = i == j ? 1 : 0;
        }
    }
}

struct Matrix* multiply(struct Matrix *a, struct Matrix *b) {
    int r = a->r, m = a->c, c = b->c;
    struct Matrix *res = create_matrix(r, c);
    for (int i = 0; i < r; ++i) {
        for (int k = 0; k < m; ++k) {
            for (int j = 0; j < c; ++j) {
                long long prod = 1LL * a->mat[i][k] * b->mat[k][j] % MOD;
                res->mat[i][j] = (res->mat[i][j] + prod) % MOD;
            }
        }
    }
    return res;
}

struct Matrix* mpow(struct Matrix *m, int n) {
    struct Matrix* res = create_matrix(m->r, m->c);
    build_identity(res);
    struct Matrix* base = create_matrix(m->r, m->c);
    for (int i = 0; i < m->r; ++i) {
        for (int j = 0; j < m->c; ++j) {
            base->mat[i][j] = m->mat[i][j];
        }
    }
    while (n) {
        if (n & 1) {
            struct Matrix *next_res = multiply(res, base);
            free_matrix(res);
            res = next_res;
        }
        struct Matrix *next_base = multiply(base, base);
        free_matrix(base);
        base = next_base;
        n >>= 1;
    }
    free_matrix(base);
    return res;
}

int numTilings(int n) {
    struct Matrix* transform = create_matrix(4, 4);
    struct Matrix* base = create_matrix(1, 4);
    int transform_data[4][4] = {
        {1, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 1, 0, 1},
        {1, 0, 0, 0}
    };
    int base_data[4] = {1, 0, 0, 0};
    set_matrix(base, base_data);
    set_matrix(transform, (int*)transform_data);
    struct Matrix *transform_pow = mpow(transform, n);

    struct Matrix* res = multiply(base, transform_pow);
    int ans = res->mat[0][0];

    free_matrix(transform);
    free_matrix(base);
    free_matrix(res);
    free_matrix(transform_pow);
    return ans;
}   