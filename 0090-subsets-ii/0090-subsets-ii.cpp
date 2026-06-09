class Solution {
public:
    void check(vector<int>& nums,vector<int>&temp,set<vector<int>>&st,int j,int n){
        if(j>=n) return;
        for(int i=j;i<n;i++){
            temp.push_back(nums[i]);
            st.insert(temp);
            check(nums,temp,st,i+1,n);
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
        set<vector<int>>st;
        check(nums,temp,st,0,n);
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};