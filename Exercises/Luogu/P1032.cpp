#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;
string src[10], dst[10];

struct { string s; int cnt; } q[2000000];
int l = 0, r = 0;
int main()
{
    cin >> a >> b;
    int len = 1;
    while (cin >> src[len] >> dst[len]) len++;

    // a 入队
    r++;
    q[r].s = a;
    q[r].cnt = 0;

    while (l < r)
    {
        l++;
        if (q[l].cnt > 10)  
        {
            cout << "NO ANSWER!" << '\n';
            return 0;
        }
        string cur = q[l].s;
        for (int i = 1; i < len; i++)
        {
            int st = cur.find(src[i]);
            // 循环，如果只执行一次，可能会漏解（后面还有子串可以替换但是没换）
            while (st != string::npos)
            {
                r++;
                q[r].s = cur;
                q[r].cnt = q[l].cnt + 1;
                q[r].s.replace(st, src[i].size(), dst[i]);
                if (q[r].s == b)
                {
                    cout << q[r].cnt << '\n';
                    return 0;
                }
                st = cur.find(src[i], st + 1);
            }
            
        }
    }

    return 0;
}