class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);

        // Build directed graph
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const long long INF = LLONG_MAX;

        // dist[node][count]
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        // {cost, node, consecutive count}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        // Starting node
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [cost, u, cnt] = pq.top();
            pq.pop();

            if (cost != dist[u][cnt])
                continue;

            // Explore neighbours
            for (auto [v, w] : adj[u]) {

                int newCount;

                if (labels[u] == labels[v])
                    newCount = cnt + 1;
                else
                    newCount = 1;

                // Invalid consecutive characters
                if (newCount > k)
                    continue;

                long long newCost = cost + w;

                if (newCost < dist[v][newCount]) {

                    dist[v][newCount] = newCost;

                    pq.push({newCost, v, newCount});
                }
            }
        }

        // Find minimum cost to reach destination
        long long ans = INF;

        for (int cnt = 1; cnt <= k; cnt++) {
            ans = min(ans, dist[n - 1][cnt]);
        }

        return ans == INF ? -1 : (int)ans;
    }
};