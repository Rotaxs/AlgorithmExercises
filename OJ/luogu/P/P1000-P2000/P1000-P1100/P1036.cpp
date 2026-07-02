#include <iostream>
#include <vector>
using namespace std;

int n, k;
int ans = 0;
vector<int> nums;
vector<bool> vis;

bool is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void dfs(int pos, int m, int cur_sum)
{
    if (pos > k)
    {
        if (is_prime(cur_sum))
            ans++;
        return;
    }
    for (int i = m; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            cur_sum += nums[i];
            dfs(pos + 1, i, cur_sum);
            cur_sum -= nums[i];
            vis[i] = false;
        }
    }
}

int main()
{
    cin >> n >> k;
    nums.resize(n);
    vis.resize(n, false);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    dfs(1, 0, 0);
    cout << ans << '\n';
    return 0;
}