/**
 * 多维资源组合优化
 * 题目描述
 * 智能控制系统需从三个独立资源池（模块A、B、C）中各选一个组件，以最大化总效能。每个模块中的组件都有其固定的效能值。一个组合的总效能等于所选三个组件的效能之和。你的任务是找出所有可能组合中，总效能最大的前K个，并按降序输出这些效能值。
 *
 * 输入格式
 * 第一行：四个整数 X, Y, Z, K，分别表示模块A、B、C的组件数量以及需要输出的最大总效能数量。
 * 第二行：X 个整数，表示模块A中各组件的效能值。
 * 第三行：Y 个整数，表示模块B中各组件的效能值。
 * 第四行：Z 个整数，表示模块C中各组件的效能值。
 *
 * 输出格式
 * 输出 K 行，第 i 行为第 i 大的总效能值（按降序排列）。
 *
 * 数据范围
 * 1 ≤ X, Y, Z ≤ 1000
 * 1 ≤ K ≤ min(3000, X×Y×Z)
 * 1 ≤ A_i, B_i, C_i ≤ 10^10
 * 所有输入均为整数。
 */
/*
样例1
输入:
2 2 2 8
4 6
1 5
3 8

输出:
19
17
15
14
13
12
10
8
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <utility>
#include <algorithm>
using namespace std;

int x, y, z, k;
vector<long long> A, B, C;

void get_effi(vector<long long> &arr, int size)
{
    long long num;
    for (int i = 0; i < size; i++)
    {
        scanf("%lld", &num);
        arr.push_back(num);
    }
}

// 使用循环嵌套遍历所有情况，效率低下，时间复杂度为O(n^2)
vector<long long> get_top_n_sums(vector<long long> &arr1, vector<long long> &arr2, int n)
{
    vector<long long> tmp;
    for (const long long &e1 : arr1)
    {
        for (const long long &e2 : arr2)
        {
            tmp.push_back(e1 + e2);
        }
    }
    sort(tmp.begin(), tmp.end(), greater<long long>());
    int count = min((int)tmp.size(), n);
    vector<long long> result(tmp.begin(), tmp.begin() + count);
    return result;
}

// topk堆合并算法，时间复杂度为O(nlogn)
vector<long long> get_top_n_sums_heap(vector<long long> &arr1, vector<long long> &arr2, int n)
{
    // 初始化返回的数组
    vector<long long> result;
    int sz = min(n, (int)(arr1.size() * arr2.size()));
    result.reserve(sz);

    // 初始化最大堆，arr1[0] + arr2[0] 一定是最大元素
    priority_queue<tuple<long long, int, int>> max_heap;
    max_heap.push({arr1[0] + arr2[0], 0, 0});

    // 初始化集合，用于存放索引列表
    set<pair<int, int>> indexs;
    indexs.insert({0, 0});

    int sz1 = arr1.size(), sz2 = arr2.size();

    while (!max_heap.empty() && result.size() < n)
    {
        // 获取堆顶元素
        auto [current_max_sum, i, j] = max_heap.top();

        result.push_back(current_max_sum);
        max_heap.pop();

        if (i + 1 < sz1)
        {
            // {i + 1, j} 不存在
            if (indexs.find({i + 1, j}) == indexs.end())
            {
                max_heap.push({arr1[i + 1] + arr2[j], i + 1, j});
                indexs.insert({i + 1, j});
            }
        }
        if (j + 1 < sz2)
        {
            if (indexs.find({i, j + 1}) == indexs.end())
            {
                max_heap.push({arr1[i] + arr2[j + 1], i, j + 1});
                indexs.insert({i, j + 1});
            }
        }
    }
    return result;
}

int main()
{
    cin >> x >> y >> z >> k;

    get_effi(A, x);
    get_effi(B, y);
    get_effi(C, z);

    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());
    sort(C.begin(), C.end(), greater<long long>());

    int n = min(k, x * y);
    vector<long long> sum_ab = get_top_n_sums_heap(A, B, n);
    vector<long long> ans = get_top_n_sums_heap(sum_ab, C, k);

    for (const long long &e : ans)
    {
        cout << e << "\n";
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <queue>
// #include <set>
// #include <tuple>

// using namespace std;

// // 使用 long long 存储效能值和总和，因为 A_i, B_i, C_i <= 10^10
// using ll = long long;

// /**
//  * @brief 堆元素结构：存储和、D数组索引、C数组索引
//  * * 使用 tuple 作为堆元素，默认比较是按照第一个元素（Sum）进行。
//  * 格式: (Sum, Index_D, Index_C)
//  */
// using HeapElement = tuple<ll, int, int>;

// /**
//  * @brief 使用最大堆找到两个已排序列表 L1 和 L2 相加后的前 K 个最大值。
//  * * @param L1 第一个已排序（降序）列表。
//  * @param L2 第二个已排序（降序）列表。
//  * @param K 需要找到的最大和数量。
//  * @return vector<ll> 包含前 K 个最大和的列表（已降序）。
//  */
// vector<ll> find_top_k_sums(const vector<ll> &L1, const vector<ll> &L2, int K)
// {
//     if (L1.empty() || L2.empty() || K == 0)
//     {
//         return {};
//     }

//     int n1 = L1.size();
//     int n2 = L2.size();

//     // 最终答案列表
//     vector<ll> result;

//     // 1. 最大堆 (Max Heap): 存储 (Sum, Index_L1, Index_L2)
//     // C++ priority_queue 默认是最大堆
//     priority_queue<HeapElement> max_heap;

//     // 2. 避免重复集合 (Visited Set): 存储 (Index_L1, Index_L2)
//     // 只有当一个索引对第一次被推入堆时，才记录在 set 中
//     set<pair<int, int>> visited;

//     // 3. 初始化：将最大的组合 (L1[0] + L2[0]) 压入堆
//     ll initial_sum = L1[0] + L2[0];
//     max_heap.push({initial_sum, 0, 0});
//     visited.insert({0, 0});

//     // 4. 循环 K 次（或直到堆为空）
//     while (result.size() < K && !max_heap.empty())
//     {
//         // 取出堆顶（当前最大的和）
//         auto [current_sum, i, j] = max_heap.top();
//         max_heap.pop();

//         // 记录为结果
//         result.push_back(current_sum);

//         // --- 探索两个新的候选 (次优解) ---

//         // 候选 1: L1 的索引 i 往后移一位 (i+1, j)
//         int next_i = i + 1;
//         if (next_i < n1)
//         {
//             if (visited.find({next_i, j}) == visited.end())
//             {
//                 ll next_sum = L1[next_i] + L2[j];
//                 max_heap.push({next_sum, next_i, j});
//                 visited.insert({next_i, j});
//             }
//         }

//         // 候选 2: L2 的索引 j 往后移一位 (i, j+1)
//         int next_j = j + 1;
//         if (next_j < n2)
//         {
//             if (visited.find({i, next_j}) == visited.end())
//             {
//                 ll next_sum = L1[i] + L2[next_j];
//                 max_heap.push({next_sum, i, next_j});
//                 visited.insert({i, next_j});
//             }
//         }
//     }

//     return result;
// }

// void solve()
// {
//     // 优化输入输出
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int X, Y, Z, K;
//     if (!(cin >> X >> Y >> Z >> K))
//         return;

//     // 1. 读取输入并存储为 long long
//     vector<ll> A(X), B(Y), C(Z);

//     for (int i = 0; i < X; ++i)
//         cin >> A[i];
//     for (int i = 0; i < Y; ++i)
//         cin >> B[i];
//     for (int i = 0; i < Z; ++i)
//         cin >> C[i];

//     // 2. 预排序：降序排列 (降序是堆合并的前提)
//     sort(A.begin(), A.end(), greater<ll>());
//     sort(B.begin(), B.end(), greater<ll>());
//     sort(C.begin(), C.end(), greater<ll>());

//     // --- 阶段 1: 合并 A 和 B ---
//     // 找出 A + B 的所有组合中前 K 个最大的和 (或所有 X*Y 个和，取较小值)
//     // 注意：我们必须找出足够的 A+B 组合才能确保最终的 K 个答案是正确的。
//     // 在最坏情况下，理论上需要 K*Z 个组合。但由于 K 较小，通常取 K 个即可。
//     // 为了保守且简化，我们取 min(K, X*Y) 个组合进行下一步。
//     int K_prime = min(K, X * Y);
//     vector<ll> AB_sums = find_top_k_sums(A, B, K_prime);

//     // --- 阶段 2: 合并 AB_sums 和 C ---
//     // 找出 (A+B) + C 的所有组合中前 K 个最大的和
//     vector<ll> final_sums = find_top_k_sums(AB_sums, C, K);

//     // 3. 输出结果
//     for (int i = 0; i < final_sums.size(); ++i)
//     {
//         cout << final_sums[i] << "\n";
//     }
// }

// int main()
// {
//     solve();
//     return 0;
// }