#include <iostream>
#include <vector>
using namespace std;

const int N = 1000;
int tree[N], n;

/**
 * 这里用树状数组维护原数组，可以实现单点修改 add() 和区间查询 sum() 洛谷 P3374
 *
 * 如果用树状数组维护差分数组，则可以很快的实现区间修改 add()（调用两次） 和单点查询（求前缀和） sum() 洛谷 P3368
 *  此时构建树状数组，可以不用读入原数组，如果要原数组的 i 位置为 v，则只需 add(i, v);add(i + 1, -v);，如此可直接得到差分数组的树状数组
 */

inline int lowbit(int x) { return x & -x; }

// 在原数组的 i 位置加 v
// 则在树状数组中，多处要加 v
void update(int i, int v)
{
    while (i <= n)
    {
        tree[i] += v;
        i += lowbit(i);
    }
}

// 返回 1 ~ i 范围的累加和
int sum(int i)
{
    int ans = 0;
    while (i > 0)
    {
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}

// 维护差分数组
void build(const vector<int> &a)
{
    for (int i = 1; i <= n; i++)
    {
        update(i, a[i]);
        update(i + 1, a[i]);
    }
}

int range(int l, int r)
{
    return sum(r) - sum(l - 1);
}

int main()
{

    return 0;
}