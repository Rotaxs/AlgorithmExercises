#include <iostream>
using namespace std;

int school[8], extra[8];

int main()
{
    for (int i = 1; i <= 7; i++)
    {
        cin >> school[i] >> extra[i];
    }
    int max_id = 0;
    int max = 0;
    int today_time;
    for (int i = 1; i <= 7; i++)
    {
        today_time = school[i] + extra[i];
        if (today_time > 8)
        {
            if (today_time > max)
            {
                max_id = i;
                max = today_time;
            }
        }
    }
    cout << max_id << endl;
    return 0;
}