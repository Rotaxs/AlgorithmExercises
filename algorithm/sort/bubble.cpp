#include <iostream>
using namespace std;

// 基础款
void bubble_sort1(int *arr, int size)
{
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
        }
    }
}

// 当只剩下一个元素时，排序其实以及完成，因此只需要进行size-1轮
void bubble_sort2(int *arr, int size)
{
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
        }
    }
}

// 当前几轮排完后，最大的数已经在最后面，我们不需要拿后来的数和这些大数比较
void bubble_sort3(int *arr, int size)
{
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - j - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
        }
    }
}

// 如果考虑有序数组，在第一轮结束后，不会发生任何交换
// 同样地，如果是部分有序的数组，在某一轮结束后的下一轮中，也不会发生交换
// 这时说明排序已经完成
void bubble_sort4(int *arr, int size)
{
    bool swapped;
    for (int j = 0; j < size - 1; j++)
    {
        swapped = false;
        for (int i = 0; i < size - j - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

// 双向冒泡
void bubble_sort5(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while (true)
    {
        for (int i = start; i <= end - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        end--;
        for (int i = end; i >= start + 1; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
            }
        }
        start++;

        if (start >= end)
        {
            break;
        }
    }
}

// 处理有序数组
void bubble_sort6(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    bool swapped = true;

    while (swapped)
    {
        swapped = false;
        for (int i = start; i <= end - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        end--;
        swapped = false;
        for (int i = end; i >= start + 1; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        start++;
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
    int arr[] = {2, 3, 5, 1, 6, 1, 5, 2, 7, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubble_sort6(arr, size);
    print(arr, size);
}
