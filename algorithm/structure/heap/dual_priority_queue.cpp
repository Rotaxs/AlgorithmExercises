#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct DualPriorityQueue {
    priority_queue<T> L, L_del; // 维护较小的一半，用大根堆
    priority_queue<T, vector<T>, greater<T>> R, R_del; // 维护较大的一半，用小根堆
    long long sum_L = 0;
    long long sum_R = 0;
    int size_L = 0;
    int size_R = 0;

    int size() const { return size_L + size_R; }
    bool empty() const { return size() == 0; }
    T median() { return median_left(); }

    void prune_L() {
        while (!L.empty() && !L_del.empty() && L.top() == L_del.top()) {
            L.pop(); L_del.pop();
        }
    }
    void prune_R() {
        while (!R.empty() && !R_del.empty() && R.top() == R_del.top()) {
            R.pop(); R_del.pop();
        }
    }
    void balance() {
        int tot = size();
        while (size_L > (tot + 1) / 2) {
            prune_L();
            T top = L.top(); L.pop();
            R.push(top);
            size_L--; size_R++;
            sum_L -= top; sum_R += top;
        }
        while (size_L < (tot + 1) / 2 && !R.empty()) {
            prune_R();
            T top = R.top(); R.pop();
            L.push(top);
            size_R--; size_L++;
            sum_R -= top; sum_L += top;
        }
    }

    void insert(const T& x) {
        prune_L(); // 确保 x 在 L 中的判断是准确的
        if (size_L == 0 || x <= L.top()) {
            L.push(x);
            size_L++; sum_L += x;
        } else {
            R.push(x);
            size_R++; sum_R += x;
        }
        balance();
    }

    void erase(const T& x) {
        prune_L(); // 确保 x 在 L 中的判断是准确的
        if (size_L > 0 && x <= L.top()) {
            L_del.push(x);
            size_L--; sum_L -= x;
        } else {
            R_del.push(x);
            size_R--; sum_R -= x;
        }
        balance();
    }

    T median_left() {
        assert(size_L > 0);
        prune_L();
        return L.top();
    }

    T median_right() {
        assert(size_R > 0);
        prune_R();
        return R.top();
    }

    long long get_abs_diff_sum() {
        if (empty()) return 0;
        long long mid = median();
        long long left_part = 1LL * mid * size_L - sum_L;
        long long right_part = sum_R - 1LL * mid * size_R;
        return left_part + right_part;
    }
};