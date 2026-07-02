#include <iostream>
#include <vector>
using namespace std;

int N, ans = 0;
vector<int> path;

void print_vec(vector<int> vec)
{
    int len = vec.size();
    for (int i = 0; i < len; i++)
    {
        cout << vec[i];
        if (i == len - 1)
            continue;
        cout << '+';
    }
    cout << '\n';
}

int get_sum()
{
    int ret = 0;
    for (const int &e : path)
    {
        ret += e;
    }
    return ret;
}

void dfs(int m)
{
    if (get_sum() > N)
        return;
    if (get_sum() == N)
    {
        print_vec(path);
        return;
    }

    for (int i = m; i < N; i++)
    {
        path.push_back(i);
        dfs(i);
        path.pop_back();
    }
}

int main()
{
    cin >> N;

    dfs(1);
    return 0;
}
