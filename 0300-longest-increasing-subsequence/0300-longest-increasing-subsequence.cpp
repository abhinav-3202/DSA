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
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return check(nums,0,n,-1,dp);
    }
};