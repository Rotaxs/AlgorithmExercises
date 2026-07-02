#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int get_len(int n)
{
    char buf[20];
    return sprintf(buf, "%d", n);
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (!(cin >> n))
        return 0;

    string s;
    char last_op;
    int a, b, res;

    while (n--)
    {
        cin >> s;
        // 如果第一个输入是字母，更新运算符并读取两个数字
        if (s[0] >= 'a' && s[0] <= 'c')
        {
            last_op = s[0];
            cin >> a >> b;
        }
        else
        {
            a = stoi(s);
            cin >> b;
        }

        string out;
        if (last_op == 'a')
        {
            res = a + b;
            out = to_string(a) + "+" + to_string(b) + "=" + to_string(res);
        }
        else if (last_op == 'b')
        {
            res = a - b;
            out = to_string(a) + "-" + to_string(b) + "=" + to_string(res);
        }
        else
        {
            res = a * b;
            out = to_string(a) + "*" + to_string(b) + "=" + to_string(res);
        }

        cout << out << endl;
        cout << out.length() << endl;
    }
    return 0;
}