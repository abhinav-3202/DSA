class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini=INT_MAX;
        if(nums.size()==1) return nums[0];
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            mini=min({mini,nums[i],nums[j]});
            i++;
            j--;
        }
        return mini;
    }
};