#include <iostream>
#include <cmath>
using namespace std;

float a, b, c;
float S, p;

int main()
{
    cin >> a >> b >> c;
    p = (a + b + c) / 2;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%.1f", S);
    return 0;
}