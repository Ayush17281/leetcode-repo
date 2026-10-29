
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n), tout(n), depth(n);
        vector<int> parent(n, -1), pref(n);
        int timer = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            parent[u] = p;
            tin[u] = timer++;

            pref[u] = (p == -1 ? 0 : pref[p])
                    ^ (1 << (s[u] - 'a'));

            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }

            tout[u] = timer;
        };

        dfs(0, -1);

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
            up[0][i] = parent[i];

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                int p = up[k - 1][i];
                if (p != -1)
                    up[k][i] = up[k - 1][p];
            }
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int k = 0; k < LOG; k++) {
                if (diff & (1 << k))
                    u = up[k][u];
            }

            if (u == v) return u;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }

            return parent[u];
        };

        // Fenwick Tree supporting range XOR updates
        // and point queries.
        vector<int> bit(n + 1, 0);

        auto add = [&](int idx, int val) {
            for (idx++; idx <= n; idx += idx & -idx)
                bit[idx] ^= val;
        };

        auto get = [&](int idx) {
            int res = 0;

            for (idx++; idx > 0; idx -= idx & -idx)
                res ^= bit[idx];

            return res;
        };

        vector<bool> answer;

        for (string &q : queries) {
            stringstream ss(q);
            string type;
            int u, v;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int delta = (1 << (s[u] - 'a'))
                          ^ (1 << (c - 'a'));

                add(tin[u], delta);

                if (tout[u] < n)
                    add(tout[u], delta);

                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);

                int pu = pref[u] ^ get(tin[u]);
                int pv = pref[v] ^ get(tin[v]);

                int pathMask = pu ^ pv
                             ^ (1 << (s[w] - 'a'));

                answer.push_back(
                    __builtin_popcount((unsigned)pathMask) <= 1
                );
            }
        }

        return answer;
    }
};
