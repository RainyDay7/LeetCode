class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        
        long **dp;
        dp = new long*[m];
        for(int i = 0; i < m; i++) {
            dp[i] = new long[n];
        }
        dp[0][0] = grid[0][0];
        for(int i=1;i<m; i++) dp[i][0] = grid[i][0]+dp[i-1][0];
        for(int j=1; j<n; j++) dp[0][j] = grid[0][j]+dp[0][j-1];
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }

        }
        long res = dp[m-1][n-1];
        // ÊÍ·Å
        for(int i = 0; i < m; i++) 
            delete [] dp[i];
        delete [] dp;
        return res;
    }
};
