class Solution {
public:
    void check(vector<int>&nums,int j,int n,vector<int>&temp,set<vector<int>>&st){
        if(j>=n){
            // st.insert(temp);
            return;
        }
        for(int i=j;i<n;i++){
            temp.push_back(nums[i]);
            st.insert(temp);
            check(nums,i+1,n,temp,st);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        set<vector<int>>st;
        st.insert(temp);
        check(nums,0,n,temp,st);
        vector<vector<int>>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};