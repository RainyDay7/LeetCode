class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        long dp[100][100]={0};
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = 0;
            }
        }
        if(obstacleGrid[0][0] == 1) return 0;
        int flag=0;
        for(int i=0; i<m; i++) {
            if(flag == 1) dp[i][0] = 0;
            
            else if(obstacleGrid[i][0]==1 ){
                if(n==1) return 0;
                flag = 1;
                dp[i][0] = 0;
            } 
            
            else dp[i][0] = 1;
        }
        flag = 0;
        for(int j=0; j<n; j++)  {
            if(flag == 1) dp[0][j] = 0;
            else  if(obstacleGrid[0][j]==1 ){
                if(m==1) return 0;
                flag =1;
                dp[0][j] = 0;
            }
            else dp[0][j] = 1;
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j]==1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }

        }
        return dp[m-1][n-1];
    }
};
