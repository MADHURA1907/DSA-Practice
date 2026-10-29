#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n, LOG, timer = 0;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, bit;
    string s;

    void add(int i, int val) {
        for (; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[u][0] = p;

        for (int j = 1; j < LOG; j++)
            up[u][j] = up[up[u][j - 1]][j - 1];

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++)
            if (diff & (1 << j))
                u = up[u][j];

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        this->n = n;
        this->s = s;
        LOG = 1;

        while ((1 << LOG) <= n) LOG++;

        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        up.assign(n, vector<int>(LOG, 0));
        bit.assign(n + 1, 0);
        timer = 0;

        dfs(0, 0);

        for (int u = 0; u < n; u++) {
            int mask = 1 << (s[u] - 'a');
            add(tin[u], mask);
            add(tout[u] + 1, mask);
        }

        vector<bool> ans;

        for (string &q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int delta = (1 << (s[u] - 'a')) ^
                            (1 << (c - 'a'));

                add(tin[u], delta);
                add(tout[u] + 1, delta);
                s[u] = c;
            } else {
                ss >> v;
                int w = lca(u, v);

                int pu = sum(tin[u]);
                int pv = sum(tin[v]);

                int mask = pu ^ pv ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> edges(n - 1, vector<int>(2));

    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    string s;
    cin >> s;

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(q);

    for (int i = 0; i < q; i++) {
        getline(cin, queries[i]);
    }

    Solution sol;
    vector<bool> ans = sol.palindromePath(n, edges, s, queries);

    cout << "[";
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i > 0) cout << ", ";
        cout << (ans[i] ? "true" : "false");
    }
    cout << "]" << endl;

    return 0;
}