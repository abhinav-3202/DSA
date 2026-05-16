class Solution {
public:
    int check(vector<vector<int>>&grid,vector<vector<int>>&dp,int m,int n,int i,int j){
        if(i==m-1 && j==n-1) return grid[m-1][n-1];
        if(i>m-1 || j>n-1) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = check(grid,dp,m,n,i,j+1);
        int down = check(grid,dp,m,n,i+1,j);
        return dp[i][j]=grid[i][j]+min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0) dp[i][j]=grid[i][j];
                else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j]=grid[i][j]+min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
        // return check(grid,dp,m,n,0,0);
    }
};