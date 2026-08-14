/**
 * 第一行输入正整数N，Q，表示字符串的长度为N，和Q次询问
 * 第二行输入一个长度为N的字符串S，由ACGT四个字符组成
 * 接下来的Q行输入区间[l, r]，格式为
 * l1 r1
 * l2 r2
 * ...
 * lq rq
 *
 * 有Q行输出，每行表示S的相应区间中连续字串ACG出现的次数
 *
 * 1<N<1e5
 * 1<=Q<1e5
 *
 *
 * 测试用例
 * 14 3
 * ACGTACGACATACG
 * 1 7
 * 2 7
 * 3 7
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // 优化输入输出效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q))
        return 0;

    string S;
    cin >> S;

    // 前缀和数组，P[i] 表示前 i 个字符中有多少个 ACG 的起始位置
    // 大小设为 N+1 以适应 1-based 索引
    vector<int> P(N + 1, 0);

    // 预处理
    // 注意：字符串 S 是 0-based 索引，题目输入是 1-based 索引
    // S[i] 对应题目中的第 i+1 个字符
    for (int i = 0; i < N; ++i)
    {
        // 继承前一个位置的数量
        P[i + 1] = P[i];

        // 检查边界，并判断是否构成 ACG
        // i 是当前检查的起始位 (对应 1-based 的 i+1)
        // 我们需要保证 i+2 不越界
        if (i + 2 < N)
        {
            if (S[i] == 'A' && S[i + 1] == 'C' && S[i + 2] == 'G')
            {
                P[i + 1]++;
            }
        }
    }

    // for (int e : P)
    // {
    //     cout << e << " ";
    // }

    // 处理询问
    for (int i = 0; i < Q; ++i)
    {
        int l, r;
        cin >> l >> r;

        // 边界情况：如果区间长度小于 3，不可能包含 ACG
        if (r - l + 1 < 3)
        {
            cout << 0 << "\n";
            continue;
        }

        // 核心公式：
        // 我们需要统计起始点在 [l, r-2] 范围内的数量
        // 利用前缀和：P[high] - P[low-1]
        // high = r - 2
        // low = l
        // 结果 = P[r-2] - P[l-1]

        cout << P[r - 2] - P[l - 1] << "\n";
    }

    return 0;
}

// #include <iostream>
// #include <string>
// using namespace std;

// const int N = 1e5 + 1;
// int n, q;
// string S;

// int Q[N][2];

// // prefix[i] 表示 S 中下标为 0 到 i-1 的 "ACG" 的数量
// int prefix[N] = {0};

// void create_prefix()
// {
//     for (int i = 0; i < n - 2; i++)
//     {
//         prefix[i + 1] = prefix[i];
//         if (S[i] == 'A' && S[i + 1] == 'C' && S[i + 2] == 'G')
//         {
//             prefix[i + 1]++;
//         }
//     }

//     // 处理最后两个位置
//     prefix[n - 1] = prefix[n - 2];
//     prefix[n] = prefix[n - 1];
// }

// int get_subarray_sum(int l, int r)
// {
//     // 区间[l, r]中"ACG"的数量
//     // "ACG"只能出现在[l, r-3]位置
//     if (r - l + 1 < 3)
//         return 0;

//     return prefix[r - 1] - prefix[l];
// }

// void print_prefix()
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << prefix[i] << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     cin >> n >> q;
//     cin >> S;

//     create_prefix();
//     print_prefix();

//     // for (int i = 0; i < q; i++)
//     // {
//     //     int l, r;
//     //     cin >> l >> r;

//     //     // 转换为0-based索引
//     //     l--;
//     //     r--;

//     //     cout << get_subarray_sum(l, r) << '\n';
//     // }

//     return 0;
// }
