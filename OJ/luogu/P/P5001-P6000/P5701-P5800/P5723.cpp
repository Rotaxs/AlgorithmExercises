#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
// vector<bool> is_prime(N);
bool is_prime[N];

int main()
{
    for (int i = 2; i < N; i++)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * 2; j < N; j += i)
                is_prime[j] = false;
        }
    }

    int l, cnt = 0, t = 2;
    long long sum = 0;
    cin >> l;
    while (l >= sum)
    {
        if (is_prime[t])
        {
            sum += t;
            if (sum <= l)
            {
                cout << t << "\n";
                cnt++;
            }
        }
        t++;
    }
    cout << cnt << "\n";

    return 0;
}