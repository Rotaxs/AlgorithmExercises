#include <iostream>
using namespace std;

const int N = 20 * 1e3;
const double PI = 3.14;

int main()
{
    int h, r;
    cin >> h >> r;
    float volume = PI * r * r * h;
    int n = (N + volume - 1) / volume;
    cout << n << endl;
    return 0;
}
