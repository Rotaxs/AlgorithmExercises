#include <iostream>
using namespace std;

const int N = 85;
int ha[N] = {0};
int S1, S2, S3;

int main()
{
    cin >> S1 >> S2 >> S3;
    for (int a = 1; a <= S1; a++)
    {
        for (int b = 1; b <= S2; b++)
        {
            for (int c = 1; c <= S3; c++)
            {
                ha[a + b + c]++;
            }
        }
    }
    int ans = 1, ans_id = 3;

    for (int i = 3; i < N; i++)
    {
        if (ha[i] > ans)
        {
            ans_id = i;
            ans = ha[i];
        }
    }
    cout << ans_id << '\n';
    return 0;
}