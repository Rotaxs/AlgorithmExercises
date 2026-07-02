#include <iostream>
using namespace std;

int s, v;

int main()
{
    cin >> s >> v;
    int t1 = s % v == 0 ? s / v : s / v + 1;
    int t2 = 10;
    int t = t1 + t2;
    int pre_hour = t / 60;
    int pre_min = t % 60;
    if (pre_hour < 8 && pre_min != 0)
        printf("%02d:%02d", 7 - pre_hour, 60 - pre_min);
    else if (pre_hour <= 8 && pre_min == 0)
        printf("%02d:%02d", 8 - pre_hour, pre_min);
    else if (pre_hour >= 8 && pre_min != 0)
        printf("%02d:%02d", 24 - (pre_hour - 8) - 1, 60 - pre_min);
    else
        printf("%02d:%02d", 24 - (pre_hour - 8), 0);
    return 0;
}