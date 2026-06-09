class Solution {
public:
    int check(string& s,string &t , int i,int j,int m,int n ,vector<vector<int>>&dp){
        if(j==n) return 1;
        if(i>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            dp[i][j]= check(s,t,i+1,j+1,m,n,dp)+
            check(s,t,i+1,j,m,n,dp);
        }
        else{
            dp[i][j]=check(s,t,i+1,j,m,n,dp);
        }
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        // if(s.size()<t.size()) return -1;
        // int count=0;
        // string temp="";
        int m=s.size();
        int n=t.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int count = check(s,t,0,0,m,n,dp);
        return count;
    }
};