#include <iostream>
#include <algorithm>
using namespace std;

void shift_up(int arr[], int i)
{
    int tmp = arr[i];
    while (i > 0 && tmp > arr[(i - 1) / 2])
    {
        arr[i] = arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    arr[i] = tmp;
}

void shift_down(int arr[], int i, int len)
{
    int tmp = arr[i];
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

void heap_sort(int arr[], int len)
{
    // 将数组堆化（这里是大根堆，所以是升序排序
    // 自顶向下建堆
    // for (int i = 0; i < len; i++)
    //     shift_up(arr, i);
    // 自底向上建堆，效率更高
    for (int i = len - 1; i >= 0; i--)
        shift_down(arr, i, len);
    // 堆化后堆顶是最大元素
    while (len > 1)
    {
        // 将最大元素与最后一个元素交换，并缩小要处理的范围
        // 此时就已经将最大元素放在最后面了
        swap(arr[0], arr[--len]);
        // 堆化
        shift_down(arr, 0, len);
    }
}

void print_arr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    heap_sort(arr, 5);
    print_arr(arr, 5);
    return 0;
}