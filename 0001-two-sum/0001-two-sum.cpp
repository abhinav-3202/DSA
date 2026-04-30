class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i = 0 ; i < nums.size();i++){
            mpp[nums[i]]=i;
        }
        for(int i = 0 ; i<nums.size();i++){
            if(mpp.find(target-nums[i]) != mpp.end() 
                && mpp[target-nums[i]]!=i){
                ans.push_back(i);
                ans.push_back(mpp[target-nums[i]]);
                break;
            }
        }
        return ans;
    }
};