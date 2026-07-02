#include <iostream>
using namespace std;

bool is_palindrome(int n)
{
    int num = n, sum = 0;
    while (n)
    {
        sum = sum * 10 + n % 10;
        n /= 10;
    }
    return num == sum;
}

int main()
{
    cout << is_palindrome(101) << endl;
    return 0;
}