#include <iostream>
using namespace std;

const int N = 2000010;
bool light[N] = {0};

int main()
{
    double a;
    int t, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> t;
        for (int j = 1; j <= t; j++)
        {
            int index = a * j;
            light[index] = light[index] ? false : true;
        }
    }
    for (int i = 1; i < N; i++)
    {
        if (light[i] == true)
        {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}