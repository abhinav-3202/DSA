class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        // int mini=INT_MAX;
        if(nums.size()==1) return nums[0];
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else if(nums[mid]<nums[high]){
                high=mid;
            }
            else if(nums[mid]==nums[high]){
                high--;
            }
        }
        return nums[low];
    }
};