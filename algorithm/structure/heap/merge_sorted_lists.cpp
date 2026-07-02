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

    // 将头结点放入堆中
    for (int h : lists)
        if (h != -1)
            pq.push({h});

    // 在 val 的有效索引最后放一个 0 占位
    int dummy = new_node(0);
    // 此时 cur 就是新的最大有效索引
    int cur = dummy;

    while (!pq.empty())
    {
        Node top = pq.top();
        pq.pop();

        // 将堆顶元素放到新的链表
        ne[cur] = top.id;
        cur = top.id;

        // 如果当前堆顶元素不是链表的最后一个元素，就插入新的元素
        if (ne[top.id] != -1)
            pq.push({ne[top.id]});
    }
    // 获取真正的头结点
    int p = ne[dummy];
    while (p != -1)
    {
        cout << val[p] << ' ';
        p = ne[p];
    }
    cout << endl;
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <string>
// #include <sstream>
// using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *ne;
//     ListNode(int x) : val(x), ne(nullptr) {}
// };

// struct Compare
// {
//     bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
// };

// priority_queue<ListNode *, vector<ListNode *>, Compare> pq;

// ListNode *merge_k_lists(vector<ListNode *> &lists)
// {
//     // 将所有链表的头结点放入小根堆
//     for (auto node : lists)
//         if (node)
//             pq.push(node);

//     ListNode head(0);
//     ListNode *tail = &head;

//     while (!pq.empty())
//     {
//         // 取出最小元素
//         ListNode *top = pq.top();
//         pq.pop();
//         // 将取出的元素放入新链表
//         tail->ne = top;
//         // 更新尾指针（当前元素）
//         tail = tail->ne;
//         // 如果（当前处理的）链表还有元素，就将新元素作为头结点放入堆
//         if (top->ne)
//             pq.push(top->ne);
//     }

//     return head.ne;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n;
//     cin >> n;
//     // 创建链表头数组，并全部初始化为 nullptr
//     vector<ListNode *> lists(n, nullptr);
//     string line;
//     getline(cin, line); // 读调 n 后面的空格

//     for (int i = 0; i < n; i++)
//     {
//         getline(cin, line);
//         if (line.empty())
//             continue;

//         // 将 line 转化为流，从而实现 ss >> num
//         stringstream ss(line);
//         int num;
//         // 虚拟头结点，简化逻辑
//         ListNode dummy(0);
//         ListNode *cur = &dummy;

//         // 将 line 中的所有 val 添加到链表
//         while (ss >> num)
//         {
//             cur->ne = new ListNode(num);
//             cur = cur->ne;
//         }
//         lists[i] = dummy.ne;

//         // 不设置虚拟头结点的写法
//         // ListNode *head = nullptr;
//         // ListNode *tail = nullptr;
//         // while (ss >> num)
//         // {
//         //     if (!head)
//         //     {
//         //         head = new ListNode(num);
//         //         tail = head;
//         //     }
//         //     else
//         //     {
//         //         tail->ne = new ListNode(num);
//         //         tail = tail->ne;
//         //     }
//         // }
//         // lists[i] = head;
//     }

//     ListNode *result = merge_k_lists(lists);

//     while (result)
//     {
//         cout << result->val << ' ';
//         result = result->ne;
//     }

//     return 0;
// }