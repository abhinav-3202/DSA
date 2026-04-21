class Solution {
public:
    vector<vector<int>>ans;
    void check(int i ,vector<int>&nums,int sum,int target,vector<int>&temp ){
        if(sum==target) {
                ans.push_back(temp);
                return;
        }
        // not adding sum>target keeps on increasing giving TLE
        if(sum > target || i==nums.size()){
            return;   
        }
        if(nums[i]>target) {
            check(i+1,nums,sum,target,temp);
        }
        else{
            temp.push_back(nums[i]);
            check(i+1,nums,sum+nums[i],target,temp);
            temp.pop_back();
            int next = i+1;
            while(next<nums.size()&&nums[i]==nums[next]){
                next++;
            }
            check(next,nums,sum,target,temp);
            return;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        int sum = 0;
        // so that a specific no can only be starting point of a combination once 
        sort(candidates.begin(),candidates.end());
        check(0,candidates,sum,target,temp);
        return ans;
    }
};