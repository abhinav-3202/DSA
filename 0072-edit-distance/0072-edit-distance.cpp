class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        // j==n s2 is exhausted insert rem s1 char
        for(int i=0;i<=m;i++){
            dp[i][n]=m-i;
        }
        //these formulas came from the recursive code
        for(int j=0;j<=n;j++){
            dp[m][j]=n-j;
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(word1[i]==word2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
                else{
                    int rep = dp[i+1][j+1];
                    int ins = dp[i][j+1];
                    int del = dp[i+1][j];
                    dp[i][j]=1+min({rep,ins,del});
                }
            }
        }
        return dp[0][0];
        // return (m-dp[m][n]);
    }
};