#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 26 + 1;
const int MAXM = 610;
int n, m;

bool g[MAXN][MAXN];
int inDegree[MAXN];
string ans = "";

bool check()
{
    int q[MAXN], l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
            q[r++] = i;
    }
    // 一层只能有一个
    if (l == r || r - l >= 2)
    {
        return false;
    }

    string order = "";
    int tmp_inDegree[MAXN];
    memcpy(tmp_inDegree, inDegree, sizeof inDegree);

    while (l < r)
    {
        int cur = q[l++];
        order += cur + 'A';
        for (int i = 1; i <= n; i++)
        {
            bool added = false;
            if (g[cur][i])
            {
                if (--tmp_inDegree[i] == 0)
                {
                    if (!added) { q[r++] = i; added = true; }
                    else return false;
                }
            }
        }
    }
    
    ans = order;
    return true;
}

// 判断 a 是否能连 b，即 a -> b
bool is_valid_arrow(int a, int b)
{
    if (a == b) return false; // 自己不能连自己
    if (g[a][b]) return false; // 如果 a 已经连过 b，不能再连
    if (g[b][a]) return false; // 如果 b 连过 a，a 就不能连 b
    // 如果已经有 b -> c1 -> c2 -> a，那么 a 不能连 b
    bool ret = true;
    for (int i = 1; i <= n; i++)
    {
        // 如果 i 是 b 连过的，检查 i 有没有连 a
        // 即判断 a 连 i 是否合法
        if (g[b][i])
            ret &= is_valid_arrow(a, i);
    }
    return ret;
}

int main()
{
    int valid_n = 0, checked_n = 0;
    bool checked = false;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        char a, b;
        scanf(" %c<%c", &a, &b);
        if (valid_n == 0 && !is_valid_arrow(a - 'A', b - 'A')) { valid_n = i; }
        // if (g[b - 'A'][a - 'A'] || a == b) { valid_n = i; }
        g[a - 'A' + 1][b - 'A' + 1] = true;
        inDegree[b - 'A']++;
        if (!checked && check())
        {
            checked_n = i;
            checked = true;
        }
    }
    if (valid_n != 0) 
        printf("Inconsistency found after %d relations.\n", valid_n);
    else if (checked)
        printf("Sorted sequence determined after %d relations: %s.\n", checked_n, ans.c_str());
    else
        printf("Sorted sequence cannot be determined.\n");

    return 0;
}