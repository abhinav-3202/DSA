class Solution {
public:
    int check(string& s1,string& s2,int i,int j,int m,int n,vector<vector<int>>&dp){
        //earlier i used here 0 return but what if word1 got exhausted in that case return the remaining words of word2
        if(i>=m) return (n-j); 
        if(j>=n) return (m-i);
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=check(s1,s2,i+1,j+1,m,n,dp);
        }
            return dp[i][j]=1+min(check(s1,s2,i+1,j+1,m,n,dp),
            min(check(s1,s2,i,j+1,m,n,dp),
            check(s1,s2,i+1,j,m,n,dp)));
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        int ans = check(word1,word2,0,0,m,n,dp);
        return ans;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // return (m-dp[m][n]);
    }
};