#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        int prod;
        array<int, 5> cnt;

        Node() {
            prod = 1;
            cnt.fill(0);
        }
    };

    int n, k;
    vector<Node> seg;
    vector<int> nums;

    Node merge(const Node& a, const Node& b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

        for (int r = 0; r < k; r++) {
            res.cnt[r] = a.cnt[r];
        }

        for (int r = 0; r < k; r++) {
            int rem = (a.prod * r) % k;
            res.cnt[rem] += b.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            int rem = nums[l] % k;
            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;
            return;
        }

        int mid = (l + r) >> 1;

        build(node << 1, l, mid);
        build(node << 1 | 1, mid + 1, r);

        seg[node] = merge(seg[node << 1], seg[node << 1 | 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = Node();

            int rem = val % k;
            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid) {
            update(node << 1, l, mid, idx, val);
        } else {
            update(node << 1 | 1, mid + 1, r, idx, val);
        }

        seg[node] = merge(seg[node << 1], seg[node << 1 | 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return seg[node];
        }

        int mid = (l + r) >> 1;

        if (qr <= mid) {
            return query(node << 1, l, mid, ql, qr);
        }

        if (ql > mid) {
            return query(node << 1 | 1, mid + 1, r, ql, qr);
        }

        Node left = query(node << 1, l, mid, ql, qr);
        Node right = query(node << 1 | 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums_,
        int k_,
        vector<vector<int>>& queries
    ) {
        nums = nums_;
        k = k_;
        n = nums.size();

        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;

    vector<vector<int>> queries = {
        {2, 2, 0, 2},
        {3, 3, 3, 0},
        {0, 1, 0, 1}
    };

    vector<int> result = sol.resultArray(nums, k, queries);

    for (int x : result) {
        cout << x << " ";
    }

    cout << '\n';

    return 0;
}