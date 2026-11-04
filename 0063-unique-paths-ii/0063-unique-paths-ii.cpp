class Solution {
public:
    int check(vector<vector<int>>&obs,vector<vector<int>>&dp,int i,int j,int m,int n){
        if(i==m-1&&j==n-1) return 1;
        if(i>=m||j>=n||obs[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = check(obs,dp,i,j+1,m,n);
        int down = check(obs,dp,i+1,j,m,n);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return check(obstacleGrid,dp,0,0,m,n);
    }
};