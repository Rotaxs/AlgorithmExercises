#include <iostream>
using namespace std;

int N, X, K;

int main()
{
    cin >> N;
    int max_x, min_k;
    for (X = 0; X <= 100; X++)
    {
        for (K = 1; K < 1000; K++)
        {
            if ((7 * X + 21 * K) * 52 == N)
            {
                max_x = X;
                min_k = K;
            }
        }
    }
    cout << max_x << '\n'
         << min_k << '\n';
    return 0;
}