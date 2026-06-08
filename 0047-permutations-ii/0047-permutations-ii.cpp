class Solution {
public:
    void check(int n,vector<int>&nums,vector<int>&temp,set<vector<int>>&st,unordered_map<int,int>&mpp){
        if(temp.size()==n){
            st.insert(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(mpp[i]==0){
                temp.push_back(nums[i]);
                mpp[i]=1;
                check(n,nums,temp,st,mpp);
                temp.pop_back();
                mpp[i]=0;
            }
        }
        return ;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        vector<int>temp;
        unordered_map<int,int>mpp;
        int n = nums.size();
        check(n,nums,temp,st,mpp);
        vector<vector<int>>ans;
        for(auto it:st){
            ans.push_back(it);
        }  
        return ans;
    }
};