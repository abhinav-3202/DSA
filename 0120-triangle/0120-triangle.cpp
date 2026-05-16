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
// the reason below we have done j<=i-1 because if we go up in the i-1 row j will not be there 
// i=1 j=1 , in i-1 j=1 not available
                    if(i>0 && j<=i-1) up= dp[i-1][j];
                    if(j>0 ) left = dp[i-1][j-1];
                    dp[i][j]=triangle[i][j]+min(up,left);
                }
            }
        }
        int maxi =INT_MAX;
        // maximum value bottom ke kisi pe bhi ho skti h 
        for(int i =0;i<n;i++){
            maxi=min(maxi,dp[n-1][i]);
        }
        return maxi;
    }
};

//dp[i][j] represents the minimum path sum required to reach the cell (i, j) starting from (0, 0)
//The History: It accumulates the values of the best possible choices made at every row above it.