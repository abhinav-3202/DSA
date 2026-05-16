class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i= 0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i==0&&j==0) dp[i][j]=triangle[i][j];
                else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i>0 && j<=i-1) up= dp[i-1][j];
                    if(j>0 ) left = dp[i-1][j-1];
                    dp[i][j]=triangle[i][j]+min(up,left);
                }
            }
        }
        int maxi =INT_MAX;
        for(int i =0;i<n;i++){
            maxi=min(maxi,dp[n-1][i]);
        }
        return maxi;
    }
};