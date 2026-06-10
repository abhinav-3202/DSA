class Solution {
public:
    int check(string& s,string &t , int i,int j,int m,int n ,vector<vector<int>>&dp){
        if(j==n) return 1;//second string t end ho gyi , means subsequence matched 
        if(i>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){//match mil gya so dono ko ek ek badha do means pick it 
            dp[i][j]= check(s,t,i+1,j+1,m,n,dp)+
            check(s,t,i+1,j,m,n,dp);
            // match mila then also not pick
        }
        else{
            dp[i][j]=check(s,t,i+1,j,m,n,dp);
            //match nhi mila then not pick obviously
        }
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<vector<unsigned int>>dp(m+1,vector< unsigned int>(n+1,0));
        // int count = check(s,t,0,0,m,n,dp);
        for(int i=0;i<=m;i++){
            dp[i][n]=1;
        }// if the length of t string is 0 then any length of s string can form subsequence 
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(s[i]==t[j]){
                    dp[i][j]=dp[i+1][j+1]+dp[i+1][j];
                }
                else {
                    dp[i][j]=dp[i+1][j];
                }
            }
        }
        return dp[0][0];
        // return count;
    }
};