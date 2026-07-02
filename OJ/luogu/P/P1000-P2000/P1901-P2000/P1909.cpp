#include <iostream>
#include <climits>
using namespace std;

int n;
int cnts[4], prices[4];
int packs[4];

int main()
{
    cin >> n;
    for (int i = 1; i <= 3; i++)
    {
        cin >> cnts[i] >> prices[i];
        packs[i] = (n + cnts[i] - 1) / cnts[i];
    }
    int final_price = INT_MAX;
    int current_money;
    for (int i = 1; i <= 3; i++)
    {
        current_money = packs[i] * prices[i];
        if (current_money < final_price)
            final_price = current_money;
    }
    cout << final_price << endl;
    return 0;
}