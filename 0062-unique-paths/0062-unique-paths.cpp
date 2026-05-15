class Solution {
public:
    int check(vector<vector<int>>&dp,int m,int n,int xx,int xy){
        if(xx==m-1 && xy==n-1) return 1;
        if(xx>m-1 || xy>n-1) return 0;
        if(dp[xx][xy]!= -1) return dp[xx][xy];
        int right = check(dp,m,n,xx+1,xy);
        int down = check(dp,m,n,xx,xy+1);
        return dp[xx][xy]=right+down;
    }
    int uniquePaths(int m, int n) {
        int ans = 0;
        int xx = 0;
        int xy = 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i = 0;i<=m-1;i++){
            for(int j = 0;j<=n-1;j++){
                if(i==0&&j==0) dp[i][j]=1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
        // return check(dp,m,n,xx,xy);
    }
};