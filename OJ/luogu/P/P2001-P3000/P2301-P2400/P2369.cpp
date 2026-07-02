#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int n, m;
priority_queue<int> pq;
stack<int> s;

int main()
{
    cin >> n >> m;
    int num;
    // 建立大根堆，每次只存 m 个元素到优先队列，空间复杂度 O(m)
    // 剩下的元素和堆顶（最大值）比较
    // 如果大于堆顶，说明不具备入队资格
    // 否则，堆顶需要弹出给新元素让位
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (i < m)
            pq.push(num);
        else
        {
            if (num < pq.top())
            {
                pq.pop();
                pq.push(num);
            }
        }
    }
    // 利用 LIFO 进行反序输出
    while (pq.size())
    {
        s.push(pq.top());
        pq.pop();
    }
    while (s.size())
    {
        cout << s.top() << '\n';
        s.pop();
    }

    return 0;
}

// ================ 小根堆，时间复杂度 O(nlogn + mlogn)，空间复杂度 O(n) ==================
// #include <iostream>
// using namespace std;

// const int N = 1e6 + 10;
// int minHeap[N], len = 0;
// int n, m;

// void push(int x)
// {
//     minHeap[len] = x;
//     int cur = len;
//     len++;
//     while (cur > 0 && x < minHeap[(cur - 1) / 2])
//     {
//         minHeap[cur] = minHeap[(cur - 1) / 2];
//         cur = (cur - 1) / 2;
//     }
//     minHeap[cur] = x;
// }

// int top()
// {
//     return minHeap[0];
// }

// int pop()
// {
//     int t = top();
//     int tmp = minHeap[0] = minHeap[--len];
//     int l, r, cur = 0, target;
//     while ((l = 2 * cur + 1) < len)
//     {
//         target = l;
//         r = l + 1;
//         if (r < len && minHeap[r] < minHeap[l])
//             target = r;
//         if (tmp <= minHeap[target])
//             break;
//         minHeap[cur] = minHeap[target];
//         cur = target;
//     }
//     minHeap[cur] = tmp;
//     return t;
// }

// int main()
// {
//     cin >> n >> m;
//     int num;
//     // 这里如果先读取所有元素到数组，然后采用自底向上堆化效率更高
//     while (n--)
//     {
//         cin >> num;
//         push(num);
//     }

//     while (m--)
//         cout << pop() << '\n';

//     return 0;
// }