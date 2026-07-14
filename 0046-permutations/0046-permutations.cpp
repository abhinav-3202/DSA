class Solution {
public:
    void check(vector<int>&temp,vector<vector<int>>&ans,unordered_map<int,int>&mpp,vector<int>& nums,int n){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(mpp[i]==0){
                temp.push_back(nums[i]);
                mpp[i]=1;
                check(temp,ans,mpp,nums,n);
                temp.pop_back();
                mpp[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        unordered_map<int,int>mpp;
        int n=nums.size();
        check(temp,ans,mpp,nums,n);
        return ans;
    }
};