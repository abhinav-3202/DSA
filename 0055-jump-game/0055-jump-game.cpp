class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0 ;
        if(nums.size()==1) return true;
        int n= nums.size();
        for(int i = 0 ; i<n;i++){
            if(maxReach>=n-1) return true;
            if(nums[i]==0 &&i>=maxReach) return false;
            maxReach = max(maxReach,i+nums[i]);
        }
        return true;
    }
};