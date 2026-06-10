class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,0);
        stack<int>st1;
        stack<int>st2;
        st1.push(temperatures[n-1]);
        st2.push(n-1);
        ans[n-1]=0;
        int i=n-2;
        while(i>=0){
            while(!st1.empty()&&!st2.empty()&&st1.top()<=temperatures[i]){
                st1.pop();
                st2.pop();
            }
            if(st1.empty()) {
                ans[i]=0;
                st1.push(temperatures[i]);
                st2.push(i);
            }
            else{
                if(!st2.empty()) ans[i]=st2.top()-i;
                st1.push(temperatures[i]);
                st2.push(i);
            }
            i--;
        }
        return ans;
    }
};