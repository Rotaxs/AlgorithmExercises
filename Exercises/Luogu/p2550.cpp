#include <iostream>
using namespace std;

const int N = 1010;

int n;
int lottery_nums[N][7];
int prize_num[7];
int prize_count[8] = {0};

int main()
{
    cin >> n;
    for (int i = 0; i < 7; i++)
        cin >> prize_num[i];

    int num;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            // cin >> lottery_nums[i][j];
            cin >> num;
            for (int k = 0; k < 7; k++)
            {
                if (prize_num[k] == num)
                {
                    count++;
                }
            }
        }
        prize_count[count]++;
        count = 0;
    }

    for (int i = 7; i >= 1; i--)
        cout << prize_count[i] << ' ';

    return 0;
}