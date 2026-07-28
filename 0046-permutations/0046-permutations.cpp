class Solution {
public:
    void check(vector<int>&nums,int prev,int n,vector<int>&temp,vector<vector<int>>&ans,unordered_map<int,int>&mpp){ 
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(mpp.find(nums[i])==mpp.end()){
                temp.push_back(nums[i]);
                mpp[nums[i]]++;
                check(nums,i+1,n,temp,ans,mpp);
                temp.pop_back();
                mpp.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        vector<int>temp;
        vector<vector<int>>ans;
        check(nums,0,n,temp,ans,mpp);
        return ans;
    }
};