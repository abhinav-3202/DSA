class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        // total el = el kept + el removed 
        // el removed(small as possible) = total - el kept(large as possible)

        // so for each index of dp1 & dp2 check for max size 
        int n=nums.size();
        vector<int>dp1(n,1);
        vector<int>dp2(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev]&&dp1[prev]+1>dp1[i]){
                    dp1[i]=1+dp1[prev];
                    // maxi1=max(maxi1,dp1[i]);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>i;prev--){
                if(nums[prev]<nums[i]&&dp2[prev]+1>dp2[i]){
                    dp2[i]=1+dp2[prev];
                    // maxi2=max(maxi2,dp2[i]);
                }
            }
        }
        int maxi=0;//lenght of longest mountain that can be kept 
        for(int i=0;i<n;i++){
            if(dp1[i]>1 && dp2[i]>1){
                maxi=max(maxi,dp1[i]+dp2[i]-1);
            }
        }
        return n-maxi;
    }
};