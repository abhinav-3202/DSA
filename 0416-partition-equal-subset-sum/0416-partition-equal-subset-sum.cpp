class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int summ=0;
        for(int i=0;i<n;i++){
            summ+=nums[i];
        }
        if(summ%2!=0) return false;
        int sum=summ/2;
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        for(int i= 0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                bool notTake = dp[i-1][j];
                bool take = false;
                if(nums[i-1]<=j) take= dp[i-1][j-nums[i-1]];
                dp[i][j]= take|| notTake;
            }
        }
        return dp[n][sum];
    }
};