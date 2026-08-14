#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
    int sum, i, j;
    bool operator>(const Node &other) const
    {
        return sum > other.sum;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // 初始将 (A[i] + B[1]) 全部入堆
    for (int i = 1; i <= n; i++)
    {
        pq.push({a[i] + b[1], i, 1});
    }

    for (int count = 0; count < n; count++)
    {
        Node top = pq.top();
        pq.pop();
        cout << top.sum << " ";

        // 每次弹出后，只向后移动 B 序列的指针
        if (top.j + 1 <= n)
        {
            pq.push({a[top.i] + b[top.j + 1], top.i, top.j + 1});
        }
    }

    return 0;
}