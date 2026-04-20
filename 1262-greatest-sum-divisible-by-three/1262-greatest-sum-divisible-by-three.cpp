class Solution {
public:
    int maxi = INT_MIN;
    // void check(vector<int>&nums,int i , int sum){
    //     if(sum%3==0){
    //         maxi = max(sum,maxi);
    //     }
    //     if(i==nums.size()) return ;
    //     check(nums,i+1,sum+nums[i]);
    //     check(nums,i+1,sum);
    // }
    int maxSumDivThree(vector<int>& nums) {
        // check(nums,0,0);
        vector<int>dp(3,0);
        for(int i = 0 ; i<nums.size();i++){
            vector<int>temp=dp;
            for(int j = 0 ;j<3;j++){
                int newSum = dp[j]+nums[i];
                int newRem = newSum%3;

                if(newSum > temp[newRem]){
                    temp[newRem]=newSum;
                }
            }
            dp = temp;
        }
        return dp[0];
    }
};