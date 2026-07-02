#include <iostream>
using namespace std;


int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main()
{
    cout << lcm(14, 4) << endl;
    return 0;
}