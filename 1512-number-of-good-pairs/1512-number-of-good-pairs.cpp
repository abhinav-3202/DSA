class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])!=mpp.end()){
                ans+=mpp[nums[i]];
            }
            mpp[nums[i]]++;
        }
        return ans;
    }
};