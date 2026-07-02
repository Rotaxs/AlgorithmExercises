#include <iostream>
#include <vector>
#include <functional>
using namespace std;

typedef long long ll;

vector<int> get_factors(int n)
{
    vector<pair<int, int>> p_factors;
    int tmp = n;
    for (int i = 2; (ll)i * i <= tmp; i++)
    {
        if (tmp % i == 0)
        {
            int cnt = 0;
            while (tmp % i == 0)
            {
                tmp /= i;
                cnt++;
            }
            p_factors.push_back({i, cnt});
        }

    }
    if (tmp > 1) p_factors.push_back({tmp, 1});

    vector<int> factors;
    function<void(int, int)> dfs = [&](int step, int f) {
        if (step == p_factors.size())
        {
            factors.push_back(f);
            return;
        }
        auto [p, k] = p_factors[step];

        int p_pow_k = 1;

        for (int i = 0; i <= k; i++)
        {
            dfs(step + 1, f * p_pow_k);
            p_pow_k *= p;
        }
    };
    dfs(0, 1);
    return factors;
}

int main()
{

    return 0;
}