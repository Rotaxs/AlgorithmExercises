#include <iostream>
using namespace std;

int m, n;
int count[10] = {0};

void updata_count(int num)
{
    int temp = num;
    while (temp)
    {
        count[temp % 10]++;
        temp /= 10;
    }
}

void print_count()
{
    for (int i = 0; i < 10; i++)
    {
        cout << count[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    cin >> m >> n;
    for (int i = m; i <= n; i++)
    {
        updata_count(i);
    }
    print_count();
    return 0;
}