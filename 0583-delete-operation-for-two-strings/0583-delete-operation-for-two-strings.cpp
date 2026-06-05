class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        // int longest = INT_MIN;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    // longest = max(longest,dp[i][j]);
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // if(longest==INT_MIN) return m+n;
        int ans = (m-dp[m][n])+(n-dp[m][n]);
        return ans;
    }
};