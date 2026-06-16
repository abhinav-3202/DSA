class Solution {
public:
    int check(string& s,string& t,int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=1+check(s,t,i-1,j-1,m,n,dp);
        }
        else{
            return dp[i][j]=max(check(s,t,i-1,j,m,n,dp),check(s,t,i,j-1,m,n,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return check(text1,text2,m-1,n-1,m,n,dp);
    }
};