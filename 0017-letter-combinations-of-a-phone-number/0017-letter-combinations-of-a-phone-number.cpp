class Solution {
public:
    void check(vector<string>&s,string &temp,vector<string>&ans,int n,int idx){
        if(idx>=n){
            ans.push_back(temp);
            return ;
        }   
        string curr=s[idx];
        for(int i=0;i<curr.size();i++){
            temp+=curr[i];
            check(s,temp,ans,n,idx+1);
            temp.pop_back();
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        vector<string>s;
        for(int i=0;i<digits.size();i++){
            if(digits[i]=='2') s.push_back("abc");
            else if(digits[i]=='3') s.push_back("def");
            else if(digits[i]=='4') s.push_back("ghi");
            else if(digits[i]=='5') s.push_back("jkl");
            else if(digits[i]=='6') s.push_back("mno");
            else if(digits[i]=='7') s.push_back("pqrs");
            else if(digits[i]=='8') s.push_back("tuv");
            else if(digits[i]=='9') s.push_back("wxyz");
        }
        int n=s.size();
        string temp;
        vector<string>ans;
        check(s,temp,ans,n,0);
        return ans;
    }
};