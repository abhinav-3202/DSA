class Solution {
public:
    int check(vector<int>&nums,int i,int n,int prev,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        if(prev+1==0 || nums[i]>nums[prev]){
            int pick = 1+check(nums,i+1,n,i,dp);
            int notPick=check(nums,i+1,n,prev,dp);
            return dp[i][prev+1]=max(pick,notPick);
        }
        else{
            return dp[i][prev+1]=check(nums,i+1,n,prev,dp);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                if(prev+1==0 || nums[i]>nums[prev]){
                    int pick=1+dp[i+1][i+1];
                    //i+1 is the prev because , prev is shifted by 1 index , ex -->>0 col prev is -1(-1+1=0) 
                    // 1 col prev is 0 as (0+1=1) 
                    int notPick=dp[i+1][prev+1];
                    dp[i][prev+1]=max(pick,notPick);
                }
                else{
                    dp[i][prev+1]=dp[i+1][prev+1];
                }
            }
        }
        return dp[0][0];
        // return check(nums,0,n,-1,dp);
    }
};