#include <iostream>
using namespace std;

int price = 19;

int main()
{
    int a, b;
    cin >> a >> b;
    int money = a * 10 + b;
    int count = money / price;
    cout << count << endl;
    return 0;
}