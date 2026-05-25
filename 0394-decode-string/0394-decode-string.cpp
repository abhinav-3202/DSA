class Solution {
public:
    void reverse(string &temp){
        int n=temp.size()-1;
        int i =0;
        while(i<n){
            swap(temp[i],temp[n]);
            i++;
            n--;
        }
        return;
    }
    string decodeString(string s) {
        int n =s.size();
        // int openCount=0;
        stack<char>st;
        int count=0,i=0;
        string ans;
        while(i<n){
            // if((s[i]>=97 && s[i]<=122)&&openCount==0){
            //     ans += s[i];
            //     // i++;
            //     // continue;
            // }
            // if(s[i]=='['){
            //     openCount++;
            //     st.push(s[i]);
            //     // continue;
            // }
            if(s[i]==']'){
                string temp;
                // openCount--;
                while(!st.empty()&&st.top()!='['){
                    temp = temp+st.top();
                    st.pop();
                }
                reverse(temp);
                if(!st.empty()) st.pop(); // to remove '['
                string num="";
                while(!st.empty()&&isdigit(st.top())){
                    num+=st.top();
                    st.pop();
                }
                reverse(num);
                int count = stoi(num);
                // st.pop();
                string str = "";
                for(int k=0;k<count;k++){
                    str += temp;
                }
                // now pushing the extracted char back into the stack  
                for(char c : str){
                    st.push(c);
                }
            }
            else{
                st.push(s[i]);
            }
            i++;
        }  
        string remInStack="";
        while(!st.empty()){
            remInStack+=st.top();
            st.pop();
        }
        reverse(remInStack);
        ans += remInStack;
        return ans; 
    }
};