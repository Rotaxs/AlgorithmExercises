#include <iostream>
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int num;
    int max = 0, min = 1000;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num > max)
            max = num;
        if (num < min)
            min = num;
    }
    cout << max - min << '\n';
    return 0;
}