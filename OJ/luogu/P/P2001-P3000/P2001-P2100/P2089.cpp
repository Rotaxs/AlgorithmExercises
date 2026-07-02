#include <iostream>
#include <vector>
using namespace std;

int N;

vector<int> path;
vector<vector<int>> res;

void dfs(int n, int pos)
{
    if (pos == 10)
    {
        int sum = 0;
        for (const int &e : path)
            sum += e;
        if (N > sum && N - sum <= 3)
        {
            path.push_back(N - sum);
            res.push_back(path);
            path.pop_back();
        }
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        path.push_back(i);
        dfs(n - i, pos + 1);
        path.pop_back();
    }
}

int main()
{
    cin >> N;
    if (N <= 30 && N >= 10)
        dfs(N, 1);

    cout << res.size() << '\n';
    for (const auto &arr : res)
    {
        for (const int &e : arr)
            cout << e << " ";
        cout << '\n';
    }

    return 0;
}