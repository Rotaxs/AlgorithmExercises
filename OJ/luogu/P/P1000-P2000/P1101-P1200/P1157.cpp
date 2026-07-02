#include <iostream>
using namespace std;

const int N = 22;

int n, r, nums[N];
bool st[N] = {false};

// pos 表示当前要处理的位置
// m 表示从哪个数开始往后搜索
void dfs(int pos, int m)
{
    if (pos > r)
    {
        for (int i = 1; i <= r; i++)
            printf("%3d", nums[i]);
        printf("\n");
        return;
    }

    for (int i = m; i <= n; i++)
    {
        if (!st[i])
        {
            st[i] = true;
            nums[pos] = i;
            dfs(pos + 1, i + 1);
            st[i] = false;
            nums[pos] = 0;
        }
    }
}

int main()
{
    cin >> n >> r;
    dfs(1, 1);
    return 0;
}