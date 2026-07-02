#include <iostream>
using namespace std;

void selection_sort1(int arr[], int size)
{
    for (int j = 0; j < size - 1; j++)
    {
        int min_index = j;
        for (int i = j + 1; i < size; i++)
        {
            if (arr[min_index] > arr[i])
            {
                min_index = i;
            }
        }
        if (min_index != j)
            swap(arr[min_index], arr[j]);
    }
}

void selection_sort2(int arr[], int size)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        int min_index = left;
        int max_index = right;
        for (int i = left; i <= right; i++)
        {
            if (arr[i] > arr[max_index])
                max_index = i;
            if (arr[i] < arr[min_index])
                min_index = i;
        }
        // 先交换最小值到左边
        if (min_index != left)
            swap(arr[min_index], arr[left]);
        // !!! 关键处理 !!!
        // 如果最大值的索引原本是 left，那么它被交换到了 min_index 的位置
        if (max_index == left)
            max_index = min_index;
        // 再交换最大值到右边
        if (max_index != right)
            swap(arr[max_index], arr[right]);
        left++;
        right--;
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {3, 5, 1, 6, 2, 7, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    selection_sort2(arr, size);
    print(arr, size);
}
