#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e6;
// val[i] 表示结点的值
// ne[i] 表示索引为 i 的元素的下一个元素的索引
// idx 表示当前元素个数
int val[N], ne[N], idx = 0;
int n;

struct Node
{
    int id;
    bool operator<(const Node &rhs) const { return val[id] > val[rhs.id]; }
};

int new_node(int x)
{
    val[idx] = x;
    ne[idx] = -1; // 用 -1 表示 val 的 idx 这个位置为空
    return idx++; // 返回新结点的索引，以方便外部上一个结点链接到该结点
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int size;
    vector<int> lists(n, -1); // 存储头结点的下标
    for (int i = 0; i < n; i++)
    {
        cin >> size;
        int num;
        int dummy = new_node(0), cur = dummy;
        while (size--)
        {
            cin >> num;
            int new_node_id = new_node(num);
            ne[cur] = new_node_id;
            cur = new_node_id;
        }
        lists[i] = ne[dummy];
    }

    priority_queue<Node> pq;

    for (int h : lists)
        if (h != -1)
            pq.push({h});

    int dummy = new_node(0);
    int cur = dummy;

    while (!pq.empty())
    {
        Node top = pq.top();
        pq.pop();

        ne[cur] = top.id;
        cur = top.id;

        if (ne[top.id] != -1)
            pq.push({ne[top.id]});
    }

    int p = ne[dummy];
    while (p != -1)
    {
        cout << val[p] << ' ';
        p = ne[p];
    }
    cout << endl;
    return 0;
}