#include <iostream>

const int N = 100000;
bool is_prime[N];

void Eratosthenes(int n)
{   
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) is_prime[i] = true;
    for (int i = 2; i <= n / i; i++)
    {
        if (is_prime[i])
        {
            for (long long j = (long long)i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

int main()
{

    return 0;
}
