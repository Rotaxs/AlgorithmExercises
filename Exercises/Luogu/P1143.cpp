#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// n 进制转 10 进制
long long to_decimal(string s, int n)
{
    long long ans = 0;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        char bit = toupper(s[len - i - 1]);
        int val;
        if (bit >= '0' && bit <= '9')
            val = bit - '0';
        else
            val = bit - 'A' + 10;
        ans += val * (long long)pow(n, i);
    }
    return ans;
}

int main()
{
    int n, m;
    string s;
    if (!(cin >> n >> s >> m))
        return 0;

    long long ten_base = to_decimal(s, n);

    if (ten_base == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    string res = "";
    while (ten_base > 0)
    {
        int bit = ten_base % m;
        if (bit <= 9)
            res += (char)(bit + '0');
        else
            res += (char)(bit - 10 + 'A');
        ten_base /= m;
    }

    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}