#include <iostream>
#include <string>
using namespace std;

string isbn;

int main()
{
    cin >> isbn;
    int sum = 0;
    sum += isbn[0] - '0';
    sum += (isbn[2] - '0') * 2;
    sum += (isbn[3] - '0') * 3;
    sum += (isbn[4] - '0') * 4;
    sum += (isbn[6] - '0') * 5;
    sum += (isbn[7] - '0') * 6;
    sum += (isbn[8] - '0') * 7;
    sum += (isbn[9] - '0') * 8;
    sum += (isbn[10] - '0') * 9;

    int identifier = sum % 11;
    if (sum % 11 == 10)
        identifier = 'X';

    int last_num = isbn[12] == 'X' ? 'X' : isbn[12] - '0';
    if (identifier == last_num)
        cout << "Right" << endl;
    else
    {
        if (identifier == 'X')
            isbn[12] = 'X';
        else
            isbn[12] = identifier + '0';
        cout << isbn << endl;
    }
    return 0;
}