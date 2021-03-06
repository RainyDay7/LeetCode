class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            dp[i][0] = (i == 0 ? 0 : dp[i - 1][0]) + grid[i][0]; // 计算第一列的结果
        }
        for(int i = 0; i < n; i++){
            dp[0][i] = (i == 0 ? 0 : dp[0][i - 1] )  + grid[0][i]; // 计算第一行的结果
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]; // 状态转移方程
            }
        }
        return dp[m - 1][n - 1];
    }
};
