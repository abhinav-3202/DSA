class Solution {
public:
    int check(vector<int>&nums,int i,int n,vector<int>&dp){
        if(i>n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int sum1= nums[i]+ check(nums,i+2,n,dp);
        int sum2= check(nums,i+1,n,dp);
        return dp[i]=max(sum1,sum2); 
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        if(n==1) return nums[0];
        return check(nums,0,n,dp);
    }
};