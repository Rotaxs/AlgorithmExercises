#include <iostream>
#include <vector>
using namespace std;

long long n;
vector<long long> factors;

void add_factor(long long &n, long long prime)
{
    while (n % prime == 0)
    {
        factors.push_back(prime);
        n /= prime;
    }
}

int main()
{
    cin >> n;
    for (long long i = 2; i * i <= n; i++)
    {
        add_factor(n, i);
    }
    if (n != 1)
    {
        factors.push_back(n);
    }
    // for (auto e : factors)
    //     cout << e << " ";
    // cout << '\n';
    cout << factors[1] << '\n';

    return 0;
}