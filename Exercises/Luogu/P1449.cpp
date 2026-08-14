#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s;
stack<int> st;

int main()
{
    cin >> s;
    int cur = 0;

    for (char c : s)
    {
        if (c >= '0' && c <= '9')
            cur = cur * 10 + (c - '0');
        else if (c == '.')
        {
            st.push(cur);
            cur = 0;
        }
        else if (c != '@')
        {
            int a, b;
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            switch (c)
            {
            case '-':
                st.push(a - b);
                break;
            case '+':
                st.push(a + b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            }
        }
    }
    cout << st.top() << '\n';
    return 0;
}