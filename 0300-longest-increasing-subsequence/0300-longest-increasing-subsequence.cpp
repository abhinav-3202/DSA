class Solution {
public: 
    int check(vector<int>&nums,int i,int n,int prev_idx,vector<vector<int>>&dp){
        if(i==n) return 0;
        // we haven't taken nums[prev_idx+1] +1 here because we have taken that value just for the dp matrix to satisfy the prev_idx+1 is only used in the dp only , other than that it is the original index of the array only 
        if(dp[i][prev_idx+1]!=-1) return dp[i][prev_idx+1];
        if(prev_idx+1==0 || nums[i]>nums[prev_idx]){
            int pick= 1+check(nums,i+1,n,i,dp);
            int notPick=check(nums,i+1,n,prev_idx,dp);
            return dp[i][prev_idx+1]=max(pick,notPick);
        }
        else{
            return dp[i][prev_idx+1]=check(nums,i+1,n,prev_idx,dp);
        }

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // int prev_idx=-1;
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            //the prev_idx cannot be beyond or == idx so it will start from one step less
            for(int prev_idx=i-1;prev_idx>=-1;prev_idx--){
                if(prev_idx+1==0 || nums[i]>nums[prev_idx]){
                    int pick= 1+dp[i+1][i+1];
                    int notPick=dp[i+1][prev_idx+1];
                    dp[i][prev_idx+1]=max(pick,notPick);
                }
                else{
                    dp[i][prev_idx+1]=dp[i+1][prev_idx+1];
                }
            }
        }
        return dp[0][0];
        // return check(nums,0,n,prev_idx,dp);
    }
};