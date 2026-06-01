class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            // vector<int>anss;
            int j=i+1;
            int k=n-1;
            int val = -nums[i];
            while(j<k){
                if(nums[j]+nums[k]==val){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                    j++;
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