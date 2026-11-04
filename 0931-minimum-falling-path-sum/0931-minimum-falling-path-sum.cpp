class Solution {
public:
    int check(vector<vector<int>>& mat,int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i>=m||j<0||j>=n) return INT_MAX;
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        if(i==m-1) return dp[i][j]=mat[i][j]; 
        return dp[i][j]=mat[i][j]+min({check(mat,i+1,j-1,m,n,dp),check(mat,i+1,j,m,n,dp),check(mat,i+1,j+1,m,n,dp)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix.size();
        int mini=INT_MAX;
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        for(int j=0;j<n;j++){
            int ans = check(matrix,0,j,m,n,dp);
            mini= min(ans,mini);
        }
        return mini;
    }
};