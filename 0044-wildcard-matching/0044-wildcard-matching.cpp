class Solution {
public:
    bool check(string &s,string &p,int i,int j,vector<vector<int>>&dp){
        if(i<0 && j<0) return true;
        if(i>=0 && j<0 ) return false;//pattern exhuasted but mathcing string is still there 
        if(i<0 && j>= 0){ //strign exhausted but pattern still there which may be * so it can be valid
            for(int k=j;k>=0;k--){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j] = check(s,p,i-1,j-1,dp);
        } 
        else if(p[j]=='*'){
            return dp[i][j] = check(s,p,i-1,j,dp) || check(s,p,i,j-1,dp);
        }
        return  dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return check(s,p,m-1,n-1,dp);
    }
};