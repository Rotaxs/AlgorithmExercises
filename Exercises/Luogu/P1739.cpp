#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s;
stack<int> st;

int main()
{
    cin >> s;
    bool flag = true;
    for (char c : s)
    {
        if (c == '(')
            st.push(c);
        if (c == ')')
        {
            if (st.size())
            {
                st.pop();
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    cout << (flag && st.empty() ? "YES" : "NO") << '\n';
    return 0;
}