#include <iostream>
#include <string>
using namespace std;

const int N = 1e5 + 10;
int n;
string t, words[N];

void shift_down(string arr[], int i, int len)
{
    string tmp = arr[i];
    int l, r, target;
    while ((l = 2 * i + 1) < len)
    {
        target = l;
        r = l + 1;
        if (r < len && arr[r] > arr[l])
            target = r;
        if (tmp > arr[target])
            break;
        arr[i] = arr[target];
        i = target;
    }
    arr[i] = tmp;
}

void shift_up(string arr[], int i)
{
    string tmp = arr[i];
    while (i > 0 && arr[(i - 1) / 2] < tmp)
    {
        arr[i] = arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    arr[i] = tmp;
}

void push(string arr[], const string x, int &len)
{
    arr[len] = x;
    shift_up(arr, len);
    len++;
}

bool check(string str, string pre)
{
    if (str == pre)
        return true;
    if (str.length() <= pre.length())
        return false;
    for (int i = 0; i < pre.length(); i++)
    {
        if (str[i] != pre[i])
            return false;
    }
    return true;
}

void swap(string &a, string &b)
{
    string c = a;
    a = b;
    b = c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> words[i];
    cin >> t;

    for (int i = n - 1; i >= 0; i--)
        shift_down(words, i, n);

    int tmp_len = n;
    while (tmp_len)
    {
        swap(words[0], words[--tmp_len]);
        shift_down(words, 0, tmp_len);
    }

    for (int i = 0; i < n; i++)
    {
        if (check(words[i], t))
            cout << words[i] << '\n';
    }

    return 0;
}