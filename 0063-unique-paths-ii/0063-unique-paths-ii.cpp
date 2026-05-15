class Solution {
public:
    int check(vector<vector<int>>&mat,vector<vector<int>>&dp,int m,int n,int i,int j){
        if(i==m-1 && j == n-1) return 1;
        if(i>m-1 || j>n-1) return 0;
        if(mat[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = check(mat,dp,m,n,i,j+1);
        int down = check(mat,dp,m,n,i+1,j);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return check(obstacleGrid,dp,m,n,0,0);
    }
};