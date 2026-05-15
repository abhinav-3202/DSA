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
        return check(dp,m,n,xx,xy);
    }
};