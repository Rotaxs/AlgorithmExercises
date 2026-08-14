#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        TreeNode *q[2001];
        // r 标记入队的元素位置，l 标记出队元素的位置
        // [l, r) 之间为队列的元素
        int l = 0, r = 0;
        q[r++] = root;
        while (l < r)
        {
            int curLevel = r - l;
            ans.push_back(vector<int>());
            for (int i = 0; i < curLevel; ++i)
            {
                TreeNode *node = q[l++];
                ans.back().push_back(node->val);
                if (node->left)
                    q[r++] = node->left;
                if (node->right)
                    q[r++] = node->right;
            }
        }

        return ans;
    }
    vector<vector<int>> levelOrder1(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size())
        {
            int curLevel = q.size();
            ans.push_back(vector<int>());
            for (int i = 1; i <= curLevel; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                ans.back().push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};