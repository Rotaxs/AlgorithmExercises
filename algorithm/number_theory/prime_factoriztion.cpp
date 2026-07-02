#include <iostream>
#include <vector>
using namespace std;

void add_factor(vector<long long> &factors, int &cnt, long long &n, int i)
{
    while (n % i == 0)
    {
        factors.push_back(i);
        cnt++;
        n /= i;
    }
}

int main()
{
    long long n, tmp_n;
    cin >> n;
    vector<long long> factors;

    int cnt = 0;
    printf("%lld=", n);

    // 把一些简单的素数先除掉，减小 n 的值
    add_factor(factors, cnt, n, 2);
    add_factor(factors, cnt, n, 3);
    add_factor(factors, cnt, n, 5);
    add_factor(factors, cnt, n, 7);

    tmp_n = n;

    for (long long i = 11; i * i <= n; i++)
    {
        add_factor(factors, cnt, n, i);
    }

    if (tmp_n > 1)
    {
        factors.push_back(tmp_n);
        cnt++;
    }

    for (long long i = 0; i < cnt; i++)
    {
        printf("%lld", factors[i]);
        if (i + 1 != cnt)
            printf("*");
    }

    return 0;
}