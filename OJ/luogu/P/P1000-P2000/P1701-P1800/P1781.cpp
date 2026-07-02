#include <iostream>
#include <string>
using namespace std;

const int N = 25;
int n, m;
string arr[N];

bool is_bigger(string str1, string str2, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (str1[i] < str2[i])
            return false;
        if (str1[i] > str2[i])
            return true;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    string max_votes = arr[0];
    int index_of_max = 0;
    int len_of_max = max_votes.length();
    for (int i = 1; i < n; i++)
    {
        int len = arr[i].length();
        if (len > len_of_max)
        {
            max_votes = arr[i];
            index_of_max = i;
            len_of_max = len;
            continue;
        }
        if (len == len_of_max && is_bigger(arr[i], max_votes, len))
        {
            max_votes = arr[i];
            index_of_max = i;
            len_of_max = len;
        }
    }

    cout << index_of_max + 1 << '\n'
         << max_votes << '\n';
    return 0;
}