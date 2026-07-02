#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int num;
    vector<int> arr;
    while (n--)
    {
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    for (int number : arr)
        cout << number << ' ';
    return 0;
}