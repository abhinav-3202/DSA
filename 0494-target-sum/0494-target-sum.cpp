class Solution {
public:
    int count=0;
    void func(vector<int>& nums, int target,int sum,int i){
        // if(i==nums.size()) return;
        if(sum == target && i==nums.size()) {
            count++;
            return;
        }
        else if(sum!=target && i==nums.size()) return;
        func(nums,target,sum+nums[i],i+1);
        func(nums,target,sum-nums[i],i+1);
        return;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        func(nums,target,0,0);
        return count;
    }
};