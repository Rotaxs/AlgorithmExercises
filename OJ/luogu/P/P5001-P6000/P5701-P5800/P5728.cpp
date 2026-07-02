#include <iostream>
using namespace std;

const int N = 1001;
int n;

int main()
{
    int ans = 0;
    int sums[N];
    int sum;
    bool sim;
    cin >> n;
    int scores[N][3];
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < 3; j++)
        {
            cin >> scores[i][j];
            sum += scores[i][j];
        }
        sums[i] = sum;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            sim = true;
            for (int k = 0; k < 3; k++)
            {
                if (abs(scores[i][k] - scores[j][k]) > 5)
                    sim = false;
            }
            if (sim)
            {
                if (abs(sums[i] - sums[j]) <= 10)
                    ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}