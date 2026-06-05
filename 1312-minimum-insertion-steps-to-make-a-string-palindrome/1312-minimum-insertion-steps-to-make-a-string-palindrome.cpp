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
        return;
    }
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        string t = s;
        rev(t);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int ans = n-dp[n][n];
        return ans;
    }
};