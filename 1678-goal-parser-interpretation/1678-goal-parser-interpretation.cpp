class Solution {
public:
    string interpret(string command) {
        string ans;
        int n=command.size();
        int i=0;
        while(i<n){
            if(command[i]=='G'){
                ans+=command[i];
                i++;
            }
            else if(command[i]=='('){
                if(command[i+1]==')'){
                    ans+='o';
                    i=i+2;
                }
                else{
                    ans+='a';
                    ans+='l';
                    i=i+4;
                }
            }
        }
        return ans;
    }
};