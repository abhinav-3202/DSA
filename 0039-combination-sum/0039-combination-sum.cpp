class Solution {
public:
    vector<vector<int>>ans;
    void func(vector<int>&nums,int i ,int target,vector<int>&temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i==nums.size()) return;
        if(nums[i]<=target){
            temp.push_back(nums[i]);
            func(nums,i,target-nums[i],temp);
            temp.pop_back();
        }
        func(nums,i+1,target,temp);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        func(candidates,0,target,temp);
        return ans;
    }
};