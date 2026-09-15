# 排序

## 归并排序

- **时间复杂度**：$O(n\log n)$；单次合并为 $O(n)$
- **空间复杂度**：$O(n)$
- **要点**：相等时先取左侧元素，可保持稳定性

```cpp
void merge(int* a, int l, int m, int r) {
    int tmp[1024];
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        // 这里 <= 保证排序的稳定性
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i <= m)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];
    memcpy(a + l, tmp + l, sizeof(int) * (r - l + 1));
}

void merge_sort_recursive(int* a, int l, int r) {
    if (l == r) return;
    int m = l + ((r - l) >> 1);
    merge_sort_recursive(a, l, m);
    merge_sort_recursive(a, m + 1, r);
    merge(a, l, m, r);
}

void merge_sort_iterative(int* a, int len) {
    int l, m, r;
    for (int step = 1; step < len; step <<= 1) {
        l = 0;
        // 分组，每组有两部分，分别为 [l, l + step - 1] 和 [l + step, r]
        // 每部分有 step 个元素
        while (l < len) {
            m = l + step - 1;
            // 表示某一组的左部分已经将剩下的元素包含完全了
            // 即当前组已经没有右侧
            if (m + 1 >= len) break;
            // 如果有右侧，就计算右侧的索引
            r = min(l + (step << 1) - 1, len - 1);
            merge(a, l, m, r);
            // 进入下一组 merge
            l = r + 1;
        }
    }
}
```

## 快速排序

- **时间复杂度**：期望 $O(n\log n)$，最坏 $O(n^2)$
- **空间复杂度**：期望 $O(\log n)$，最坏 $O(n)$
- **要点**：随机选择 `pivot`，将区间原地分成 `< pivot`、`== pivot`、`> pivot` 三段

```cpp
PII partition(vector<int>& arr, int l, int r) {
    int pivot = arr[l + rand() % (r - l + 1)];
    int m = l;
    while (m <= r) {
        if (arr[m] == pivot)
            m++;
        else if (arr[m] > pivot)
            swap(arr[m], arr[r--]);
        else
            swap(arr[m++], arr[l++]);
    }
    return {l, r};
}

void quick_sort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    auto [low, high] = partition(arr, l, r);
    quick_sort(arr, l, low - 1);
    quick_sort(arr, high + 1, r);
}
```


