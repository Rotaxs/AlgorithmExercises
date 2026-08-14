#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int sum, score;
    double max, avg, res = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        int maxn = 0, minn = 10;
        for (int j = 0; j < m; j++)
        {
            cin >> score;
            sum += score;
            if (score > maxn)
                maxn = score;
            if (score < minn)
                minn = score;
        }
        sum -= maxn;
        sum -= minn;
        avg = (double)sum / (m - 2);
        if (avg - res > 1e-6)
            res = avg;
    }
    printf("%.2lf", res);
    return 0;
}