class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int mini=INT_MAX;
        while(i<=j){
            mini=min({mini,nums[i],nums[j]});
            i++;
            j--;
        }
        return mini;
    }
};