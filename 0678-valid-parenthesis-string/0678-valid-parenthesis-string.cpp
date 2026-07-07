class Solution {
public:
    bool checkValidString(string s) {
        int close=0;
        int n=s.size();
        stack<int>st1;
        stack<int>st2;
        for(int i=0;i<n;i++){
            if(s[i]=='*') st2.push(i);
            else if(s[i]=='('){
                st1.push(i);
            }
            else{
                if(!st1.empty()) st1.pop();
                else if(!st2.empty()){
                    st2.pop();
                }
                else return false;
            }
        }
        if(st1.size()>st2.size()) return false;
        while(!st1.empty() && !st2.empty()){
            int top1 = st1.top();
            st1.pop();
            int top2 = st2.top();
            st2.pop();
            if(top1>top2){
                return false;
            }
        }
        return true;
    }
};