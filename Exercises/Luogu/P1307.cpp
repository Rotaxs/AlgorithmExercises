#include <iostream>
using namespace std;

int N;

int main()
{
    cin >> N;
    int sum = 0;
    while (N)
    {
        sum = sum * 10 + N % 10;
        N /= 10;
    }
    cout << sum << '\n';
    return 0;
}