#include <iostream>
#include <string>
using namespace std;

const int N = 1010;
string names[N];
int scores[3][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
        for (int s = 0; s < 3; s++)
            cin >> scores[s][i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum_a = 0, sum_b = 0;
            bool is_sim = true;
            for (int s = 0; s < 3; s++)
            {
                int a = scores[s][i], b = scores[s][j];
                sum_a += a;
                sum_b += b;
                is_sim &= abs(a - b) <= 5;
            }
            is_sim &= abs(sum_a - sum_b) <= 10;
            if (is_sim)
                cout << names[i] << ' ' << names[j] << '\n';
        }
    }
    return 0;
}