#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> path;

void print_vec(vector<int> &vec)
{
    for (const int &e : vec)
    {
        cout << e << ' ';
    }
    cout << '\n';
}

// =================================================

/*
    选数法
    按字典序遍历
*/

void dfs_choose_number(int m, int cur_sum)
{
    if (cur_sum > N)
        return;
    if (cur_sum == N)
    {
        print_vec(path);
        return;
    }

    for (int i = m; i <= N - cur_sum; i++)
    {
        path.push_back(i);
        dfs_choose_number(i, cur_sum + i);
        path.pop_back();
    }
}

// ====================================================================
/*
    选位法
    按长度遍历，且需要外层循环
*/

// 全排列
void dfs(int n, int d)
{
    if (d == 1)
    {
        int sum = 0;
        for (const int &e : path)
            sum += e;
        if (N - sum > 0)
        {
            path.push_back(N - sum);
            print_vec(path);
            path.pop_back();
        }
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        path.push_back(i);
        dfs(n - i, d - 1);
        path.pop_back();
    }
}

// 组合
void dfs(int n, int d, int m)
{
    if (d == 1)
    {
        if (n >= m)
        {
            path.push_back(n);
            print_vec(path);
            path.pop_back();
        }
        return;
    }

    for (int i = m; i <= n; i++)
    {
        path.push_back(i);
        dfs(n - i, d - 1, i);
        path.pop_back();
    }
}

int main()
{
    cin >> N;
    for (int i = N; i >= 2; i--)
        dfs(N, i, 1);

    // dfs_choose_number(1, 0);
    return 0;
}
