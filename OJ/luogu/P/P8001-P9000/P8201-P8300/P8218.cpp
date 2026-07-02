/*
    给定由 n 个正整数组成的序列，分别求这 m 个区间的区间和。
    输入格式
        第一行包含一个正整数 n，表示序列的长度。
        第二行包含 n 个正整数
        第三行包含一个正整数 m，表示区间的数量。
        接下来 m 行，每行包含两个正整数 l, r
    输出格式
        共 m 行，其中第 i 行包含一个正整数，表示第 i 组答案的询问。
*/

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> P;
vector<int> nums;

void init_pre()
{
    int sz = nums.size();
    P.resize(sz + 1);
    P[0] = 0;
    for (int i = 1; i < sz; i++)
    {
        P[i] = P[i - 1];
        P[i] += nums[i];
    }
}

void print_pre()
{
    for (int e : P)
    {
        cout << e << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int tmp;
    nums.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        nums.push_back(tmp);
    }

    init_pre();

    cin >> m;
    int l, r;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        cout << P[r] - P[l - 1] << "\n";
    }

    return 0;
}