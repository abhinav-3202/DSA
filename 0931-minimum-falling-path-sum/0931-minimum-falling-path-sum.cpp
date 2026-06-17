class Solution {
public:
    int check(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(j<0 || j>n-1) return INT_MAX;
        if(i==n-1) return dp[i][j]=matrix[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        return dp[i][j]=matrix[i][j]+min({
            check(i+1,j,n,matrix,dp),
            check(i+1,j+1,n,matrix,dp),
            check(i+1,j-1,n,matrix,dp),
        });
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int j=0;j<n;j++){
            ans=min(ans,check(0,j,n,matrix,dp));
        }
        return ans;
    }
};