class Solution {
public:
    void check(vector<int>&nums,int j,int n,vector<int>&temp,vector<vector<int>>&ans){
        if(j>=n){
            // st.insert(temp);
            return;
        }
        for(int i=j;i<n;i++){
            temp.push_back(nums[i]);
            ans.push_back(temp);
            check(nums,i+1,n,temp,ans);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        vector<vector<int>>ans;
        ans.push_back(temp);
        check(nums,0,n,temp,ans);
        return ans;
    }
};