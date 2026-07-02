#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c;

int main()
{
    cin >> a >> b >> c;
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);
    bool is_triangle = a + b > c;
    bool is_right = a * a + b * b == c * c;
    bool is_acute = a * a + b * b > c * c;
    bool is_obtuse = a * a + b * b < c * c;
    bool is_isosceles = a == b || a == c || b == c;
    bool is_equilateral = a == b && b == c;

    if (!is_triangle)
        cout << "Not triangle" << endl;
    else
    {
        if (is_right)
            cout << "Right triangle" << endl;
        if (is_acute)
            cout << "Acute triangle" << endl;
        if (is_obtuse)
            cout << "Obtuse triangle" << endl;
        if (is_isosceles)
            cout << "Isosceles triangle" << endl;
        if (is_equilateral)
            cout << "Equilateral triangle" << endl;
    }

    return 0;
}