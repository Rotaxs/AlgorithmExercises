#include <iostream>
using namespace std;

float t;
int n;

int main()
{
    cin >> t >> n;
    float vol_per_stu = t / n;
    int bottle = 2 * n;
    printf("%.3f\n", vol_per_stu);
    printf("%d\n", bottle);
    return 0;
}
