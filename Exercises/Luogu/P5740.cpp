#include <iostream>
#include <string>
using namespace std;

const int N = 1010;
string names[N];

int main()
{
    int n;
    cin >> n;
    string name;
    int a, b, c, max_a, max_b, max_c;
    int max_id = 0, max_score = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        cin >> a >> b >> c;
        names[i] = name;
        if (a + b + c > max_score)
        {
            max_score = a + b + c;
            max_a = a;
            max_b = b;
            max_c = c;
            max_id = i;
        }
    }
    cout << names[max_id] << ' '
         << max_a << ' '
         << max_b << ' '
         << max_c << '\n';

    return 0;
}