#include <bits/stdc++.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param tree TreeNode类 
     * @return int整型
     */

    const int MOD = 1e9 + 7;

    long long qpow(long long a, long long n) {
        long long res = 1;
        while (n) {
            if (n & 1) res = res * a % MOD;
            a = a * a % MOD;
            n >>= 1;
        }
        return res;
    }

    int getHeight(TreeNode *tree) {
        if (!tree) return 0;
        return 1 + std::max(getHeight(tree->left), getHeight(tree->right));
    }

    int getTreeSum(TreeNode* tree) {
        int height = getHeight(tree);
        return (qpow(2, height) - 1 + MOD) % MOD;
    }
};