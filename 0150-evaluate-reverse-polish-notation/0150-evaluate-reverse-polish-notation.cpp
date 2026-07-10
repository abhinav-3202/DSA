class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        //points to remember 
        //1.faced the issue of stoi conversion
        //2. i was using '+' instead of "+" , for string use""
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){ 
                int t2=st.top(); 
                st.pop();
                int t1=st.top();
                st.pop();
                int ans;
                if(tokens[i]=="+"){
                    ans=t1+t2;
                    st.push(ans);
                }
                else if(tokens[i]=="-"){
                    ans=t1-t2;
                    st.push(ans);
                }
                else if(tokens[i]=="*"){
                    ans=t1*t2;
                    st.push(ans);
                }
                else {
                    ans=t1/t2;
                    st.push(ans);
                }
            }
            else{ 
                st.push(stoi(tokens[i]));
            }
        }
        if(!st.empty()){
            int anss=st.top();
            return anss;
        }
        return 0;
    }
};