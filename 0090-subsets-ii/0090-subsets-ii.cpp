class Solution {
public:
    void check(vector<int>& nums,vector<int>&temp,vector<vector<int>>&ans,int j,int n){
        if(j>=n) return;
        for(int i=j;i<n;i++){
            // dery run in revision copy 
            if(i>j && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            ans.push_back(temp);
            check(nums,temp,ans,i+1,n);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n =nums.size();
        vector<int>temp;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        ans.push_back(temp);
        // set<vector<int>>st;
        check(nums,temp,ans,0,n);
        return ans;
    }
};