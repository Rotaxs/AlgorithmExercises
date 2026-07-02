/**
 * 并查集：并查集是一种管理元素所属集合的数据结构，其主要实现两个功能
 * - 合并（Unite）：合并两个元素所属的集合
 * - 查询（Find）：查找某个元素所属的集合（根结点），可用于判断两个元素是否属于同一个集合
 *
 * 注：并查集中我们并不关心某个元素的父结点、子节点是谁，只关系这个元素属于哪个集合，即该元素的根结点
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 1;

// fa[i]表示元素i的父结点
int fa[N];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        // 初始化，使得所有的元素的父节点是自己（没有建立任何关系，一个元素就是一个集合）
        fa[i] = i;
    }
}

int find(int x)
{
    if (fa[x] == x)
        return x;
    // fa[x]表示x的父节点
    // 使用递归找到x的根节点
    return find(fa[x]);
}

void unite(int i, int j)
{
    // 使得j成为i的根结点
    fa[find(i)] = find(j);
}

// =========================================================================

/*
    需要注意的是，当不断地将一个树并到另一个结点时，这个树地深度会不断加大
    因此每次通过递归找某个元素的根结点时，会增大时间复杂度

    要解决这个问题，可以采用路径压缩的方式
        即在每次调用find()函数时，顺带将元素的父结点设置为根结点
        使得该树趋于“扁平化”，这样在第二次查询时只要一次递归就能找到相应的根结点

    路径压缩虽然会改变树的结构，但这不是我们需要关心的
*/

int find_path_compression(int x)
{
    // if (fa[x] == x)
    //     return x;
    // fa[x] = find_path_compression(fa[x]);
    // return fa[x];

    // 用三目运算符简化
    return x == fa[x] ? x : (fa[x] = find_path_compression(fa[x]));
}

// 既然我们不考虑一个集合中结点与结点之间的关系，我们还可以在合并集合时简化
// 即将小树并入大树，可以有效减小树的深度

// 定义一个结点的秩，表示当前结点的高度
int ranks[N];

void init_ranked(int n)
{
    for (int i = 0; i < n; i++)
    {
        fa[i] = i;
        ranks[i] = 1;
    }
}

void unite_ranked(int i, int j)
{
    int x = find(i), y = find(j);
    if (x == y)
        return;
    // 确保 x 的秩大于 y 的秩
    if (ranks[x] < ranks[y])
        swap(x, y);
    fa[y] = x; // 小树并入大树
    // 如果两树的秩相同，那么将小树并入大树时会多出一个结点
    if (ranks[x] == ranks[y])
        ranks[x]++;
}

// ==========================================================================

int main()
{

    return 0;
}