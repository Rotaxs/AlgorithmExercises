#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000;
const int WORD_LEN = 128;
bool is_prime[N] = {false};
int cnt[27] = {0};

void init_prime()
{
    for (int i = 0; i < N; i++)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < N; j += i)
                is_prime[j] = false;
        }
    }
}

int main()
{
    init_prime();
    char str[WORD_LEN + 1];
    cin >> str;
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] >= 'a' ? str[i] - 'a' + 'A' : str[i];
        cnt[str[i] - 'A']++;
    }
    int maxn = 0, minn = WORD_LEN;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] != 0)
        {
            maxn = max(cnt[i], maxn);
            minn = min(cnt[i], minn);
        }
    }
    int diff = maxn - minn;
    // cout << "maxn = " << maxn << '\n';
    // cout << "minn = " << minn << '\n';
    if (is_prime[diff])
        cout << "Lucky Word" << '\n'
             << diff << '\n';
    else
        cout << "No Answer" << '\n'
             << 0 << '\n';

    return 0;
}