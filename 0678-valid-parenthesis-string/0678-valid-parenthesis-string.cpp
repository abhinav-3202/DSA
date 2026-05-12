class Solution {
public:
    bool checkValidString(string s) {
        int left = 0 ;
        int right = 0;
        // int star = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='*') left++;
            else right++;
            if(right>left) return false;
        }
        left = 0;
        right = 0; 
        for(int i = s.size()-1;i>=0;i--){
            if(s[i]==')' || s[i]=='*') right++;
            else left++;
            if(left>right) return false;
        }
        return true;
    }
};