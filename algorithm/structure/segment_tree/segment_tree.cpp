#include "bits/stdc++.h"
using namespace std;

// ---------- Info 与 Tag 定义 ----------
// 默认：维护区间和，支持区间加法

struct Info {
    long long sum;
    int len; // 区间长度，apply 时会用到
    Info() : sum(0), len(0) {}
    Info(long long s, int l) : sum(s), len(l) {}
};

// Info 合并：两个子区间信息合并为父区间信息
Info operator+(const Info& a, const Info& b) {
    return Info(a.sum + b.sum, a.len + b.len);
}

struct Tag {
    long long add; // 区间加法的增量
    Tag() : add(0) {}
    Tag(long long v) : add(v) {}
};

// 标记叠加：先后两个 Tag 作用在同一区间，合并为一个 Tag
void operator+=(Tag& a, const Tag& b) {
    a.add += b.add;
}

// 标记作用于信息：将 Tag 作用在 Info 上
void apply(Info& a, const Tag& b) {
    a.sum += b.add * a.len;
}
// --------------------------------------------------

template <class Info, class Tag>
struct SegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;

    SegmentTree() {}
    SegmentTree(int n_) { init(n_); }
    
    template <typename T>
    SegmentTree(const vector<T>& a) { init(a); }

    void init(int n_) {
        n = n_;
        int size = 1;
        while (size < n) size <<= 1;
        info.assign(size << 1, Info());
        tag.assign(size << 1, Tag());
    }

    template <typename T>
    void init(const vector<T>& a) {
        init((int)a.size());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = Info(a[l], 1);
                return;
            }
            int m = (l + r) >> 1;
            build(p << 1, l, m);
            build(p << 1 | 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }

    void pull(int p) {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }

    void apply(int p, const Tag& v) {
        ::apply(info[p], v); // 调用全局 apply
        tag[p] += v;
    }

    void push(int p) {
        apply(p << 1, tag[p]);
        apply(p << 1 | 1, tag[p]);
        tag[p] = Tag();
    }

    // 区间查询 [l, r)  0-indexed 左闭右开
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }

    Info rangeQuery(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return info[p];
        if (qr <= l || r <= ql) return Info();
        push(p);
        int m = (l + r) >> 1;
        return rangeQuery(p << 1, l, m, ql, qr)
             + rangeQuery(p << 1 | 1, m, r, ql, qr);
    }

    // 区间修改 [l, r)  0-indexed 左闭右开
    void rangeApply(int l, int r, const Tag& v) {
        rangeApply(1, 0, n, l, r, v);
    }

    void rangeApply(int p, int l, int r, int ql, int qr, const Tag& v) {
        if (ql <= l && r <= qr) {
            apply(p, v);
            return;
        }
        if (qr <= l || r <= ql) return;
        push(p);
        int m = (l + r) >> 1;
        rangeApply(p << 1, l, m, ql, qr, v);
        rangeApply(p << 1 | 1, m, r, ql, qr, v);
        pull(p);
    }

    // 单点修改
    void set(int idx, const Info& v) {
        set(1, 0, n, idx, v);
    }

    // 树上二分：找到第一个 sum >= k 的位置，返回下标，找不到返回 -1
    int findFirst(long long k) {
        if (info[1].sum < k) return -1;
        return findFirst(1, 0, n, k);
    }

    int findFirst(int p, int l, int r, long long& k) {
        if (r - l == 1) return l;
        push(p);
        int m = (l + r) >> 1;
        if (info[p << 1].sum >= k)
            return findFirst(p << 1, l, m, k);
        k -= info[p << 1].sum;
        return findFirst(p << 1 | 1, m, r, k);
    }
};