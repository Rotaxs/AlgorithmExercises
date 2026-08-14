#include <iostream>
using namespace std;

const int N = 1e6 + 10;
// 小根堆
int arr[N], len = 0;
int n;

int get_peek() { return arr[0]; }

void shift_up(int i)
{
    int tmp = arr[i];
    while (i > 0 && tmp < arr[(i - 1) / 2])
    {
        arr[i] = arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    arr[i] = tmp;
}

void shift_down(int i, int len)
{
    int tmp = arr[i];
    int l, target;
    while ((l = i * 2 + 1) < len)
    {
        target = l;
        int r = l + 1;
        if (r < len && arr[r] < arr[l])
            target = r;
        if (tmp <= arr[target])
            break;
        arr[i] = arr[target];
        i = target;
    }
    arr[i] = tmp;
}

void push(int x)
{
    arr[len] = x;
    shift_up(len++);
}

void pop()
{
    if (len <= 0)
        return;
    if (len == 1)
    {
        len--;
        return;
    }
    arr[0] = arr[--len];
    shift_down(0, len);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int op, x;
    while (n--)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> x;
            push(x);
            break;
        case 2:
            cout << get_peek() << '\n';
            break;
        case 3:
            pop();
            break;
        }
    }
    return 0;
}