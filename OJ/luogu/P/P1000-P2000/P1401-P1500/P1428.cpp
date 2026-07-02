#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> fish;

int main()
{
    cin >> n;
    fish.resize(n);
    for (int i = 0; i < n; i++)
        cin >> fish[i];
    int cnt;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 0; j <= i; j++)
        {
            if (fish[j] < fish[i])
                cnt++;
        }
        cout << cnt << " ";
    }
    return 0;
}