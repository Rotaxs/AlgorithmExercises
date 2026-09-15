# STL

## `set` 和 `multiset`

两者均为有序红黑树；`set` 元素唯一，`multiset` 允许重复。

- **时间复杂度**：`insert`/查找/按值 `erase`/`lower_bound`/`upper_bound` 为 $O(\log n)$；遍历区间再加输出量
- **空间复杂度**：$O(n)$
- `lower_bound(x)` 返回第一个 $\ge x$ 的元素，`upper_bound(x)` 返回第一个 $>x$ 的元素
- 最小/最大元素：`*begin()` / `*prev(end())`

## `map` 和 `unordered_map`

- **时间复杂度**：`map` 查改删为 $O(\log n)$；`unordered_map` 期望 $O(1)$，最坏 $O(n)$
- **空间复杂度**：$O(n)$
- 需要键有序或 `lower_bound`/`upper_bound` 时用 `map`；只做快速查改时优先 `unordered_map`
