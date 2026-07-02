#include <iostream>
using namespace std;

const int N = 100;

struct TreeNode
{
    int key;
    TreeNode *left;
    TreeNode *right;
    int size;  // 当前节点为根的子树大小
    int count; // 当前节点的重复数量

    TreeNode(int value)
        : key(value), size(1), count(1), left(nullptr), right(nullptr) {}
};



int main()
{

    return 0;
}