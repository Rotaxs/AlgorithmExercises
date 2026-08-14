#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;
    int luo = n * 3 + 11;
    int loc = n * 5;
    if (loc < luo)
        cout << "Local" << endl;
    else
        cout << "Luogu" << endl;
    return 0;
}
