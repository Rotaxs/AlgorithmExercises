#include <iostream>
using namespace std;

const int N = 110;
int arr[N];

int main()
{
    int num = 1;
    int cnt = 0;
    while (1)
    {
        scanf("%d", &num);
        if (num == 0)
            break;
        arr[cnt++] = num;
    }
    for (int i = cnt - 1; i >= 0; i--)
        cout << arr[i] << " ";

    return 0;
}