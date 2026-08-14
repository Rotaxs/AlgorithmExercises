#include <iostream>
using namespace std;

// n = qR + r = (q + 1)R + r - R

void solution(int n, int R)
{
    if (n == 0)
        return;
    int r = n % R;
    int q = n / R;
    if (r < 0)
    {
        r -= R;
        q++;
    }
    solution(q, R);
    if (r <= 9)
        cout << r;
    else
        cout << (char)(r + 'A' - 10);
}

int main()
{
    int n, R;
    cin >> n >> R;
    printf("%d=", n);
    solution(n, R);
    printf("(base%d)", R);
    return 0;
}