#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int s1, s2, s3, s4;
vector<int> S1, S2, S3, S4;
vector<bool> vis;
int ans, ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX, ans4 = INT_MAX;

/*
    把做题看成一个连续的过程
    对于一个科目的题，将做题的总时间看成两部分：左脑做题时间 + 右脑做题时间
    要想时间最短，只需要左脑的做题时间 和 右脑的做题时间差最小
*/

void print(vector<int> vec)
{
    for (const int &e : vec)
    {
        cout << e << ' ';
    }
    cout << '\n';
}

void read(vector<int> &S, const int &s)
{
    S.resize(s);
    for (int i = 0; i < s; i++)
        cin >> S[i];
}

void dfs(int &ans, int step, int left, int right, vector<int> &S)
{
    if (max(left, right) > ans)
        return;
    if (step == S.size())
    {
        ans = min(ans, max(right, left));
        return;
    }

    dfs(ans, step + 1, left + S[step], right, S);
    dfs(ans, step + 1, left, right + S[step], S);
}

int main()
{
    cin >> s1 >> s2 >> s3 >> s4;
    read(S1, s1);
    read(S2, s2);
    read(S3, s3);
    read(S4, s4);

    vis.resize(25);

    dfs(ans1, 0, 0, 0, S1);
    dfs(ans2, 0, 0, 0, S2);
    dfs(ans3, 0, 0, 0, S3);
    dfs(ans4, 0, 0, 0, S4);
    ans = ans1 + ans2 + ans3 + ans4;
    cout << ans << '\n';

    return 0;
}