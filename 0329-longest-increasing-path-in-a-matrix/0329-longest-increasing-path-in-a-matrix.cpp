class Solution {
public:
    int check(vector<vector<int>>& matrix,int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i>=m||j>=n||i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=0,right=0,up=0,down=0;
        if(j>=1 && matrix[i][j]<matrix[i][j-1]){
            left=check(matrix,i,j-1,m,n,dp);
        }
        if(j<n-1&&matrix[i][j]<matrix[i][j+1]){
            right=check(matrix,i,j+1,m,n,dp);
        }
        if(i>=1 && matrix[i][j]<matrix[i-1][j]){
            up=check(matrix,i-1,j,m,n,dp);
        }
        if(i<m-1 && matrix[i][j]<matrix[i+1][j]){
            down=check(matrix,i+1,j,m,n,dp);
        }
        return dp[i][j]=1+max({left,right,up,down});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int maxi=1;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                maxi=max(maxi,check(matrix,i,j,m,n,dp));
            }
        }
        return maxi;
    }
};