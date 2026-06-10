class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        // j==n s2 is exhausted insert rem s1 char
        //if j==0 then rem char = i because i dosenot denote index it denotes length of rem char
        for(int i=0;i<=m;i++){
            dp[i][0]=i;
        }
        //these formulas came from the recursive code
        for(int j=0;j<=n;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int rep = dp[i-1][j-1];
                    int ins = dp[i][j-1];
                    int del = dp[i-1][j];
                    dp[i][j]=1+min({rep,ins,del});
                }
            }
        }
        return dp[m][n];
        // return (m-dp[m][n]);
    }
};