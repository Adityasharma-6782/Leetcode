
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> tin(n), tout(n), depth(n);
        vector<int> parent(n), base(n);
        vector<int> order;
        order.reserve(n);

        // Iterative DFS
        vector<int> st = {0};
        parent[0] = 0;
        base[0] = 1 << (s[0] - 'a');

        int timer = 0;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            tin[u] = timer++;
            order.push_back(u);

            up[0][u] = parent[u];

            for (int v : adj[u]) {
                if (v == parent[u]) continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                base[v] = base[u] ^ (1 << (s[v] - 'a'));

                st.push_back(v);
            }
        }

        // Calculate subtree sizes
        vector<int> sz(n, 1);

        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            sz[parent[u]] += sz[u];
        }

        for (int u = 0; u < n; u++) {
            tout[u] = tin[u] + sz[u] - 1;
        }

        // Binary lifting
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        // LCA
        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = LOG - 1; j >= 0; j--) {
                if (diff & (1 << j))
                    u = up[j][u];
            }

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        // Fenwick Tree: Range XOR Update, Point Query
        vector<int> bit(n + 2, 0);

        auto add = [&](int i, int val) {
            for (; i <= n; i += i & -i)
                bit[i] ^= val;
        };

        auto rangeUpdate = [&](int l, int r, int val) {
            add(l + 1, val);
            add(r + 2, val);
        };

        auto pointQuery = [&](int i) {
            int res = 0;

            for (i++; i > 0; i -= i & -i)
                res ^= bit[i];

            return res;
        };

        vector<bool> ans;
        ans.reserve(queries.size());

        for (const string &q : queries) {
            stringstream ss(q);

            string type;
            int u, v;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int change = (1 << (s[u] - 'a')) ^
                             (1 << (c - 'a'));

                rangeUpdate(tin[u], tout[u], change);

                s[u] = c;
            }
            else {
                ss >> v;

                int w = lca(u, v);

                int pu = base[u] ^ pointQuery(tin[u]);
                int pv = base[v] ^ pointQuery(tin[v]);

                int mask = pu ^ pv ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
