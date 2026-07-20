#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int findTargetSumWays1(vector<int>& nums, int target)
    {
        return dfs1(nums, target, 0, 0);
    }
    int dfs1(vector<int> &nums, int target, int cur_sum, int i)
    {
        if (i == nums.size())
        {
            if (cur_sum == target) return 1;
            return 0;
        }
        return dfs1(nums, target, cur_sum + nums[i], i + 1) + dfs1(nums, target, cur_sum - nums[i], i + 1);
    }

    int findTargetSumWays2(vector<int> &nums, int target)
    {
        unordered_map<string, int> memo;
        return dfs2(nums, target, 0, 0, memo);
    }
    int dfs2(vector<int> &nums, int target, int cur_sum, int i, unordered_map<string, int> &memo)
    {
        if (i == nums.size())
            return cur_sum == target ? 1 : 0;
        string key = to_string(i) + "_" + to_string(cur_sum);
        if (memo.count(key)) return memo[key];
        int res = dfs2(nums, target, cur_sum + nums[i], i + 1, memo) + dfs2(nums, target, cur_sum - nums[i], i + 1, memo);
        return memo[key] = res;
    }

    int N = 1000;
    int findTargetSumWays3(vector<int> &nums, int target)
    {
        vector<vector<int>> memo(nums.size(), vector<int>(N * 2 + 1, -1));
        return dfs3(nums, target, 0, 0, memo);
    }
    int dfs3(vector<int> &nums, int target, int cur_sum, int i, vector<vector<int>> &memo)
    {
        if (i == nums.size()) return cur_sum == target ? 1 : 0;
        if (memo[i][cur_sum + N] != -1) return memo[i][cur_sum + N];
        return memo[i][cur_sum + N] = dfs3(nums, target, cur_sum + nums[i], i + 1, memo) + dfs3(nums, target, cur_sum - nums[i], i + 1, memo);
    }

    int findTargetSumWays4(vector<int> &nums, int target)
    {
        int sum = 0, n = nums.size();
        for (int &x : nums) sum += x;
        vector<vector<int>> dp(n + 1, vector<int>(sum * 2 + 1, 0));

        dp[n][target + sum] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = -sum; j <= sum; j++)
            {
                if (j - nums[i] + sum >= 0)
                    dp[i][j + sum] = dp[i + 1][j - nums[i] + sum];
                if (j + nums[i] + sum >= 0)
                    dp[i][j + sum] += dp[i + 1][j + nums[i] + sum];
            }
        }
        return dp[0][sum];
    } 
};