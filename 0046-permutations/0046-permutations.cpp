class Solution {
public:
    void check(int j,int n,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,unordered_map<int,int>&mpp){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i =0;i<n;i++){
            if(mpp[i]==0){
                temp.push_back(nums[i]);
                mpp[i]=1;
                check(i,n,nums,temp,ans,mpp);
                temp.pop_back();
                mpp[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        unordered_map<int,int>mpp;
        int n = nums.size();
        check(0,n,nums,temp,ans,mpp);
        return ans;
    }
};