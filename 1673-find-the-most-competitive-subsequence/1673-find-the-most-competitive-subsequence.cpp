class Solution {
public:
    void reverse(vector<int>& ans){
        int n=ans.size()-1;
        int i=0;
        while(i<n){
            swap(ans[i],ans[n]);
            i++;
            n--;
        }
        return;
    }
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // here i was applying the backward pass , but it disrupts the building order of the subsequence 
        int n = nums.size();
        int i = 0;
        stack<int>st;
        while(i<=n-1){
            if(st.empty()){
                st.push(nums[i]);
                i++;
            }
            else{
                while(!st.empty() && st.top()>nums[i] && (st.size()+n-i-1)>=k){
                    st.pop();
                }
                if(st.size()<k) st.push(nums[i]);
                i++;
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans);
        return ans;
    }
};