#include <iostream>
using namespace std;

void insertion_sort1(int arr[], int size)
{
    // 已排序部分元素个数
    int n = 1;
    while (n < size)
    {
        // 遍历已排序部分
        for (int i = 0; i < n; i++)
        {
            if (arr[n] < arr[i])
            {
                int temp = arr[n];
                // 从索引为i到索引为n-1的元素整体后移，覆盖原来索引为n的位置，并空出索引为i的位置
                for (int j = n - 1; j >= i; j--)
                {
                    arr[j + 1] = arr[j];
                }
                arr[i] = temp;
                break;
            }
        }
        // 完成一次插入，已排序部分元素加1
        n++;
    }
}

void insertion_sort2(int arr[], int size)
{
    // 索引i对应的元素表示当前循环要操作的元素
    for (int i = 1; i < size; i++)
    {
        // 用key记录操作数
        int key = arr[i];
        // j从操作数的前一位开始依次与key进行比较
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            // 如果key>=arr[j]，表示上一次比较后，已经将所有比key大的元素移到后面
            // 那么上一次比较时的索引j（即当前循环比较的索引j+1）所对应的元素就被空出来了
            if (key >= arr[j])
                break;
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

void insertion_sort3(int arr[], int size)
{

    // 0 ~ 0 有序 ✔
    // 0 ~ 1 有序 ✔
    // 0 ~ 2 有序 ✔
    // 0 ~ i 有序 ✔
    // 0 ~ size - 1 有序 ✔
    for (int i = 1; i <= size - 1; i++)
        for (int j = i - 1; j >= 0 && arr[j + 1] < arr[j]; j--)
            swap(arr[j + 1], arr[j]);
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
    int arr[] = {2, 1, 3, 4, 6, 5, 3, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertion_sort2(arr, size);
    print(arr, size);
    return 0;
}