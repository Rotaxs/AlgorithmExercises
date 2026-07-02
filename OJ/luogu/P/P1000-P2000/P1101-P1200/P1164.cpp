#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 110;
const int MAXM = 10010;
int n, m;
int price[MAXN] = {0};
// mem[i][j] 表示从第 i 个无凭开始选，且当前已经凑了金额 j 时，后续能凑成 m 的方案数
long long mem[MAXN][MAXM];

long long dfs(int index, int target)
{
    if (target == 0)
        return 1;
    if (index == n || target < 0)
        return 0;
    if (mem[index][target] != -1)
        return mem[index][target];
    long long res = dfs(index + 1, target - price[index]) + dfs(index + 1, target);
    return mem[index][target] = res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> price[i];
    memset(mem, -1, sizeof mem);

    cout << dfs(0, m) << '\n';
    return 0;
}