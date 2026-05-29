class Solution {
public:
    bool check(string &temp){
        int i=0;
        int j=temp.size()-1;
        while(i<=j){
            if(temp[i]!=temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]>=97&&s[i]<=122){
                temp+=s[i];
            }
            else if(s[i]>=65 && s[i]<=90){
                char ch = s[i]+32;
                temp+= ch;
            }
            else if(s[i]>=48 && s[i]<=57){
                temp+=s[i];
            }
        }
        return check(temp);
    }
};