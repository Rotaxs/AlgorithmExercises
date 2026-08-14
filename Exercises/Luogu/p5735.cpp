#include <iostream>
#include <cmath>
using namespace std;

double dis(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    double x1, x2, x3, y1, y2, y3;
    double res;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    res = dis(x1, y1, x2, y2) + dis(x2, y2, x3, y3) + dis(x3, y3, x1, y1);
    printf("%.2f", res);
    return 0;
}