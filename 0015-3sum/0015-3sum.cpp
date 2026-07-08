class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i =0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;//for duplicates in starting 
            int val = -nums[i];
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[j]+nums[k]==val){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1]) j++;//duplicates
                    while(j<k && nums[k]==nums[k-1]) k--;//duplicates
                    j++; // jhere at 2,2 after while j will be at next so both have been used so j++ again
                    k--;
                }
                else if(nums[j]+nums[k]<val){
                    j++;
                }
                else k--;
            }
        }
        return ans;
    }
};