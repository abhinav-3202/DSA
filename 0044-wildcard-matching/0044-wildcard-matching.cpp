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
        // how base cases were thought , firstly convert <0 to ==0
        // for 1 based indexing and >= to >0 only and write base case
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        // for(int i=1;i<=m;i++){
        //     dp[i][0]=false;
        // }  //no need for this initailization because already declared as false;
        for(int j=1;j<=n;j++){
            if(p[j-1]=='*'){
                dp[0][j]=dp[0][j-1]; // we are taking true only if all previous were true or all previous were *
                // else it is false only  
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j]= dp[i][j-1] || dp[i-1][j];
                }
                else dp[i][j]=false;
            }
        }
        return dp[m][n];
        // return check(s,p,m-1,n-1,dp);
    }
};