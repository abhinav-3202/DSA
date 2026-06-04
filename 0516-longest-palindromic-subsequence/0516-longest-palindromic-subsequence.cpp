class Solution {
public:
    void rev(string &t){
        int i=0;
        int j=t.size()-1;
        while(i<j){
            swap(t[i],t[j]);
            i++;
            j--;
        }
        return ;
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string t=s;
        rev(t);
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    // ans=max(ans,dp[i][j]);
                }
                // in case of substring or subarray it will be dp[i][j]=0, because ek bhi same nhi rha then subarray will not form , but for subsequence this can be carried on 
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
        // return ans;
    }
};