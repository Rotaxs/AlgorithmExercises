#include <iostream>
using namespace std;

const int N = 210;
int mat[N * N];

int main()
{
    int n, num, sum = 0, index = 0;
    bool zero = true;
    cin >> n;
    while (sum < n * n)
    {
        cin >> num;
        int i;
        for (i = index; i < num + index; i++)
        {
            if (zero)
                mat[i] = 0;
            else
                mat[i] = 1;
        }
        index = i;
        zero = !zero;
        sum += num;
    }
    for (int i = 0; i < n * n; i++)
    {
        cout << mat[i];
        if ((i + 1) % n == 0)
            cout << '\n';
    }
    return 0;
}