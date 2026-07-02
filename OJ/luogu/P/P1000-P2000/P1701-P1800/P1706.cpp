#include <iostream>
using namespace std;

const int N = 10;
int n, nums[N];
// st[i] 表示 i 这个数有没有被选过
bool st[N] = {false};

void dfs(int pos)
{
    if (pos > n)
    {
        for (int i = 1; i <= n; i++)
            printf("%5d", nums[i]);
        printf("\n");
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            // 记录状态
            st[i] = true;
            nums[pos] = i;
            dfs(pos + 1);
            // 回溯
            st[i] = false;
            nums[pos] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
    return 0;
}