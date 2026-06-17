class Solution {
public:
    bool check(int i,int j,int n,string &s,vector<string>& wordDict,vector<vector<int>>&dp){
        if(i==n) return true;
        if(j==n) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        string temp=s.substr(i,j-i+1);
        if(count(wordDict.begin(),wordDict.end(),temp)>0){
            if(i==n-1||j==n-1) return true;
            return dp[i][j]=check(i,j+1,n,s,wordDict,dp)||check(j+1,j+1,n,s,wordDict,dp);
        }
        return dp[i][j]=check(i,j+1,n,s,wordDict,dp);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return check(0,0,n,s,wordDict,dp);
    }
};