#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
long long tree1[N], tree2[N];

int lowbit(int x) { return x & -x; }

// 对于差分树状数组效果：将原数组 i 后面的元素全部加 v
void update(long long tree[], int i, long long v)
{
    while (i <= n)
    {
        tree[i] += v;
        i += lowbit(i);
    }
}

long long sum(long long tree[], int i)
{
    long long ret = 0;
    while (i >= 1)
    {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}

// 对于差分数组：将原数组 l ~ r 的数加 v
void add(int l, int r, long long v)
{
    update(tree1, l, v);
    update(tree1, r + 1, -v);
    update(tree2, l, (long long)(l - 1) * v);
    update(tree2, r + 1, -(long long)r * v);
}

long long range(int l, int r)
{
    return sum(tree1, r) * r - sum(tree2, r) - (sum(tree1, l - 1) * (l - 1) - sum(tree2, l - 1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    long long num;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        add(i, i, num);
    }
    while (m--)
    {
        int op, x, y;
        long long k;
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> x >> y >> k;
            add(x, y, k);
            break;
        case 2:
            cin >> x >> y;
            cout << range(x, y) << '\n';
            break;
        }
    }
    return 0;
}