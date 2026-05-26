class Solution {
public:
    void right(vector<vector<int>>& matrix,vector<vector<int>>&dp,vector<int>&ans,int m,int n,int i,int j){
        if(i >= m || i < 0 || j >= n || j < 0 || dp[i][j] == -1) {
            return;
        }
        int a;
        for(a =j ;a<n;a++){
            if(dp[i][a]==-1){
                down(matrix,dp,ans,m,n,i+1,a-1);
                return;
            }
            ans.push_back(matrix[i][a]);
            dp[i][a]=-1;
        }
        //loop finished and a is at n so a-1
        down(matrix,dp,ans,m,n,i+1,a-1);
        return ;
    }
    void down(vector<vector<int>>& matrix,vector<vector<int>>&dp,vector<int>&ans,int m,int n,int i,int j){
        int a;
        if(i >= m || i < 0 || j >= n || j < 0 || dp[i][j] == -1) {
            return;
        }
        for( a =i ;a<m;a++){
            if(dp[a][j]==-1){
                left(matrix,dp,ans,m,n,a-1,j-1);
                return;
            }
            ans.push_back(matrix[a][j]);
            dp[a][j]=-1;
        }
        left(matrix,dp,ans,m,n,a-1,j-1);
        return ;
    }
    void left(vector<vector<int>>& matrix,vector<vector<int>>&dp,vector<int>&ans,int m,int n,int i,int j){
        if(i >= m || i < 0 || j >= n || j < 0 || dp[i][j] == -1) {
            return;
        }
        int a;
        for(a = j ;a>=0;a--){
            if(dp[i][a]==-1){
                up(matrix,dp,ans,m,n,i-1,a+1);
                return;
            }
            ans.push_back(matrix[i][a]);
            dp[i][a]=-1;
        }
        up(matrix,dp,ans,m,n,i-1,a+1);
        return ;
    }
    void up(vector<vector<int>>& matrix,vector<vector<int>>&dp,vector<int>&ans,int m,int n,int i,int j){
        if(i >= m || i < 0 || j >= n || j < 0 || dp[i][j] == -1) {
            return;
        }
        int a;
        for( a =i ;a>=0;a--){
            if(dp[a][j]==-1){
                right(matrix,dp,ans,m,n,a+1,j+1);
                return;
            }
            ans.push_back(matrix[a][j]);
            dp[a][j]=-1;
        }
        right(matrix,dp,ans,m,n,a+1,j+1);
        return ;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        vector<int>ans;
        right(matrix,dp,ans,m,n,0,0);
        return ans;
    }
};