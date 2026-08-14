#include <iostream>
using namespace std;

int x;

int main()
{
    cin >> x;
    float price;
    if (x <= 150)
        price = x * 0.4463;
    else if (x <= 400)
        price = 150 * 0.4463 + (x - 150) * 0.4663;
    else
        price = 150 * 0.4463 + 250 * 0.4663 + (x - 400) * 0.5663;

    // cout << price << endl;
    printf("%.1f", price);
    return 0;
}