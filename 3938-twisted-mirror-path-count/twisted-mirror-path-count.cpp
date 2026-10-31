class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> R(m, vector<int>(n, -1));
        vector<vector<int>> D(m, vector<int>(n, -1));

        // Precompute mirror destinations
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (grid[i][j] == 0) {
                    R[i][j] = i * n + j;
                    D[i][j] = i * n + j;
                }
                else {
                    if (i + 1 < m)
                        R[i][j] = D[i + 1][j];

                    if (j + 1 < n)
                        D[i][j] = R[i][j + 1];
                }
            }
        }

        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dp[i][j] == 0) continue;

                // Move right
                if (j + 1 < n && R[i][j + 1] != -1) {
                    int pos = R[i][j + 1];
                    int x = pos / n;
                    int y = pos % n;

                    dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                }

                // Move down
                if (i + 1 < m && D[i + 1][j] != -1) {
                    int pos = D[i + 1][j];
                    int x = pos / n;
                    int y = pos % n;

                    dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};