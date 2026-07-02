#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

const int LEN = 500;

// 判断回文
bool is_pala(const vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - 1 - i])
            return false;
    }
    return true;
}

// 进制加法：m = m + reverse(m)
vector<int> add_reverse(vector<int> a, int base)
{
    vector<int> b = a;
    reverse(b.begin(), b.end());

    vector<int> res;
    int carry = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int sum = a[i] + b[i] + carry;
        res.push_back(sum % base);
        carry = sum / base;
    }
    if (carry)
        res.push_back(carry);
    return res;
}

int main()
{
    int n;
    string s;
    if (!(cin >> n >> s))
        return 0;

    vector<int> m;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (isdigit(s[i]))
            m.push_back(s[i] - '0');
        else
            m.push_back(toupper(s[i]) - 'A' + 10);
    }

    for (int step = 0; step <= 30; step++)
    {
        if (is_pala(m))
        {
            cout << "STEP=" << step << endl;
            return 0;
        }
        m = add_reverse(m, n);
    }

    cout << "Impossible!" << endl;
    return 0;
}