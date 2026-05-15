class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // return check(obstacleGrid,dp,m,n,0,0);
        for(int i = 0;i<=m-1;i++){
            for(int j =0;j<=n-1;j++){
                if(i==0 && j==0 && obstacleGrid[i][j]==0) dp[i][j]=1;
                else if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else {
                    int up = 0;
                    int left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};