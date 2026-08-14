#include <iostream>
using namespace std;

const int N = 1e5 + 10;
bool is_prime[N];

int main()
{
    for (int i = 0; i < N; i++)
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
    int n, num;

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> num;
        if (is_prime[num])
            cout << num << ' ';
    }

    return 0;
}