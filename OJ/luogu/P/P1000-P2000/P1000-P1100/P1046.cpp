#include <iostream>
using namespace std;

int stool = 30;
int heights[10];
int height;

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cin >> heights[i];
    }
    cin >> height;
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        if (heights[i] <= height + stool)
            cnt++;
    }
    cout << cnt << endl;

    return 0;
}