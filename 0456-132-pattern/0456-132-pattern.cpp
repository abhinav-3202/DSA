class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>st;
        int kth = INT_MIN;
        for(int i = nums.size()-1;i>=0;i--){
            if(nums[i]<kth){//2 element phle se ready h
                return true;
            }
            //agar nums[i] greater h meaning wo 2 element or j banne layak h , so upar wale ko kth bana do ..... and last me 2 or j ko wapas stack me push kar do ....
            // as soon as ek milega kth se chota means condition satisfy 
            while(!st.empty()&& nums[i]>st.top()){
                kth = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};