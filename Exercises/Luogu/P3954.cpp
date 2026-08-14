#include <iostream>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int score = 0.2 * A + 0.3 * B + 0.5 * C;
    cout << score << endl;
    return 0;
}