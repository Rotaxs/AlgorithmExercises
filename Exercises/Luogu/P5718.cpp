#include <iostream>
#include <climits>
using namespace std;

int n;

int main()
{
    cin >> n;
    int min = INT_MAX, num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num < min)
            min = num;
    }
    cout << min << endl;
    return 0;
}