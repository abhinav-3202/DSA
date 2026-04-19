class Solution {
public:
    vector<vector<int>>ans;
    void func(vector<int>&nums,int i , int sum,int target,vector<int>&temp){
        if(i==nums.size()) return;
        sum = sum+nums[i];
        // if(sum>target) return;
        temp.push_back(nums[i]);
        if(sum == target){
            ans.push_back(temp);
            // temp.pop_back();
            // sum = sum-nums[i];
            // return;
            //early return wala galat thaa becoz sum aane ke baad baaki paths nhi explore kar rha tha
        }
        if(sum<target) func(nums,i,sum,target,temp);
        temp.pop_back();
        func(nums,i+1,sum-nums[i],target,temp);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        func(candidates,0,0,target,temp);
        return ans;
    }
};