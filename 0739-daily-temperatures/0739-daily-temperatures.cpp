class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,0);
        stack<int>st1;
        st1.push(n-1);
        ans[n-1]=0;
        int i=n-2;
        while(i>=0){
            while(!st1.empty()&&temperatures[st1.top()]<=temperatures[i]){
                st1.pop();
            }
            if(!st1.empty()) ans[i]=st1.top()-i;
            st1.push(i);
            i--;
        }
        return ans;
    }
};