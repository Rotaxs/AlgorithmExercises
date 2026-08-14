#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Compare = less<T>>
struct DualMultiset {
    multiset<T, Compare> L;
    multiset<T, Compare> R;
    Compare cmp;
    
    long long sum_L = 0;
    long long sum_R = 0;

    DualMultiset(Compare c = Compare()) : cmp(c), L(c), R(c) {}
    size_t size() const { return L.size() + R.size(); }
    bool empty() const { return size() == 0; }
    const T& median() const { return median_left(); } // 针对元素个数为奇数的中位数的情况
    
    void balance() {
        size_t tot = size();
        while (L.size() > ((tot + 1) >> 1)) {
            auto it = prev(L.end());
            sum_L -= *it;
            sum_R += *it;
            R.insert(L.extract(it));
        }
        while (L.size() < ((tot + 1) >> 1) && !R.empty()) {
            auto it = R.begin();
            sum_R -= *it;
            sum_L += *it;
            L.insert(R.extract(it));
        }
    }
    
    const T& median_left() const {
        assert(!L.empty());
        return *prev(L.end());
    }
    
    const T& median_right() const {
        assert(!R.empty());
        return *R.begin();
    }
    
    void insert(const T& x) {
        if (L.empty() || !cmp(median_left(), x)) {
            L.insert(x);
            sum_L += x;
        } else {
            R.insert(x);
            sum_R += x;
        }
        balance();
    }
    
    void erase(const T& x) {
        auto it = L.find(x);
        if (it != L.end()) {
            sum_L -= *it;
            L.erase(it);
        } else {
            auto it2 = R.find(x);
            if (it2 != R.end()) {
                sum_R -= *it2;
                R.erase(it2);
            }
        }
        balance();
    }

    // 计算当前集合所有元素到中位数的距离之和: 
    // (右半部分和 - 右半部分个数 * 中位数) + (左半部分个数 * 中位数 - 左半部分和)
    long long get_abs_diff_sum() const {
        if (empty()) return 0;
        long long mid = median();
        long long right_part = sum_R - 1LL * R.size() * mid;
        long long left_part = 1LL * L.size() * mid - sum_L;
        return right_part + left_part;
    }
};