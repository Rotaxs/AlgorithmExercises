#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 按照字典序排列
char light[] = {'B', 'G', 'R'};

void solve()
{
    string s;
    cin >> s;
    int len = s.size();
    if (len == 1)
    {
        cout << "B\n";
        return;
    }
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '?')
        {
            // 这里其实可以考虑减少条件判断（设置虚拟边界）
            // 如果 ? 在开头
            if (i == 0)
            {
                for (int c = 0; c < 3; c++)
                {
                    // 只需检查后面的
                    if (s[i + 1] != light[c])
                    {
                        // 贪心：找字典序最小的
                        s[i] = light[c];
                        break;
                    }
                }
            }
            // ? 在中间
            else if (i == len - 1)
            {
                for (int c = 0; c < 3; c++)
                {
                    // 检查前面的
                    if (s[i - 1] != light[c])
                    {
                        s[i] = light[c];
                        break;
                    }
                }
            }
            // ? 在结尾
            else
            {
                for (int c = 0; c < 3; c++)
                {
                    // 检查两边的
                    if (s[i - 1] != light[c] && s[i + 1] != light[c])
                    {
                        s[i] = light[c];
                        break;
                    }
                }
            }
        }
    }
    cout << s << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}