#include <iostream>
#include <vector>
using namespace std;

int N, M;
int cnt = 0;
vector<bool> state;
vector<int> hand;
vector<int> order;

void dfs(int pos)
{
    if (pos > N)
    {
        cnt++;
        if (cnt == M + 1)
        {
            for (int &e : hand)
                cout << e << " ";
            cout << '\n';
            exit(0);
        }
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        // 比如外星人手指为 1 2 4 3 5
        // 那么下面个判断可以让 hand 的状态变为 1 2 4 3 5 且保持 cnt = 0
        if (cnt == 0)
        {
            i = order[pos];
        }
        if (!state[i])
        {
            state[i] = true;
            hand.push_back(i);
            dfs(pos + 1);
            hand.pop_back();
            state[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;
    state.resize(N + 1);
    order.resize(N + 1);
    int num;
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        order[i] = num;
    }
    dfs(1);
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <map>
// using namespace std;

// int N, M;
// int cnt = 1;
// vector<int> hand;
// // state[i] 表示第 i 根手指有没有被用过
// vector<bool> state;
// // 火星人手指太多存不下了（雾）
// map<int, vector<int>> hands;

// void dfs(int pos)
// {
//     if (pos > N)
//     {
//         hands[cnt++] = hand;
//         return;
//     }
//     for (int i = 1; i <= N; i++)
//     {
//         if (state[i] == false)
//         {
//             state[i] = true;
//             hand.push_back(i);
//             dfs(pos + 1);
//             hand.pop_back();
//             state[i] = false;
//         }
//     }
// }

// int main()
// {
//     cin >> N >> M;
//     int finger;
//     state.resize(N + 1, false);
//     dfs(1);

//     for (int i = 0; i < N; i++)
//     {
//         cin >> finger;
//         hand.push_back(finger);
//     }

//     int cnt;
//     for (const auto &[val, arr] : hands)
//     {
//         if (arr == hand)
//         {
//             cnt = val;
//             break;
//         }
//     }
//     cnt += M;
//     for (const int &e : hands[cnt])
//     {
//         cout << e << " ";
//     }
//     cout << '\n';
//     return 0;
// }