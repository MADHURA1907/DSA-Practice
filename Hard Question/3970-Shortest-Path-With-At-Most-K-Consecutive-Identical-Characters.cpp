#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        // {distance, node, consecutive count}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        if(k < 1) return -1;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {

            auto [d, u, cnt] = pq.top();
            pq.pop();

            if(d != dist[u][cnt]) continue;

            if(u == n - 1) return d;

            for(auto [v, w] : adj[u]) {

                int newCnt;

                if(labels[u] == labels[v]) {
                    newCnt = cnt + 1;
                }
                else {
                    newCnt = 1;
                }

                if(newCnt > k) continue;

                long long newDist = d + w;

                if(newDist < dist[v][newCnt]) {

                    dist[v][newCnt] = newDist;

                    pq.push({newDist, v, newCnt});
                }
            }
        }

        return -1;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> edges(m, vector<int>(3));

    for(int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    string labels;
    cin >> labels;

    Solution s;
    cout << s.shortestPath(n, edges, labels, k) << endl;

    return 0;
}