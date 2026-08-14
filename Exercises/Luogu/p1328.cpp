#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

int n, na, nb;
vector<int> a_order, b_order;
// comp[i][j] 表示 A 出 i，B 出 j，A 的得分
int comp[5][5] = {
    {0, 0, 1, 1, 0},
    {1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 0, 0, 0}};

/*
        0   1   2   3   4
    0   0   -1  +1  +1  -1
    1   +1  0   -1  +1  -1
    2   -1  +1  0   -1  +1
    3   -1  -1  +1  0   +1
    4   +1  +1  -1  -1  0
*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> na >> nb;
    a_order.resize(na);
    b_order.resize(nb);

    for (int i = 0; i < na; i++)
        cin >> a_order[i];
    for (int i = 0; i < nb; i++)
        cin >> b_order[i];

    int score_a = 0, score_b = 0;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        // if (ia == na)
        //     ia = 0;
        // if (ib == nb)
        //     ib = 0;
        int ia = i % na;
        int ib = i % nb;
        // cout << "a: " << a_order[ia] << " " << "b: " << b_order[ib] << endl;
        a = a_order[ia];
        b = b_order[ib];

        score_a += comp[a][b];
        score_b += comp[b][a];

        // 暴力模拟
        // if (a == 0)
        // {
        //     if (b == 2 || b == 3)
        //         score_a++;
        //     else if (b == 1 || b == 4)
        //         score_b++;
        // }
        // if (a == 1)
        // {
        //     if (b == 0 || b == 3)
        //         score_a++;
        //     else if (b == 2 || b == 4)
        //         score_b++;
        // }
        // if (a == 2)
        // {
        //     if (b == 1 || b == 4)
        //         score_a++;
        //     else if (b == 0 || b == 3)
        //         score_b++;
        // }
        // if (a == 3)
        // {
        //     if (b == 2 || b == 4)
        //         score_a++;
        //     else if (b == 0 || b == 1)
        //         score_b++;
        // }
        // if (a == 4)
        // {
        //     if (b == 0 || b == 1)
        //         score_a++;
        //     else if (b == 2 || b == 3)
        //         score_b++;
        // }
    }

    cout << score_a << " " << score_b << "\n";

    return 0;
}