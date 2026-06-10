class Solution {
public:
    void check(vector<string>&s,string &temp,vector<string>&ans,int n){
        for(int i=0;i<s[0].size();i++){
            string s1=s[0];
            temp+=s1[i];
            if(s.size()==1){
                ans.push_back(temp);
                temp.pop_back();
            }
            else{
                for(int j=0;j<s[1].size();j++){
                    string s2=s[1];
                    temp+=s2[j];
                    if(s.size()==2){
                        ans.push_back(temp);
                        temp.pop_back();
                    }
                    else{
                        for(int k=0;k<s[2].size();k++){
                            string s3=s[2];
                            temp+=s3[k];
                            if(s.size()==3){
                                ans.push_back(temp);
                                temp.pop_back();
                            }
                            else{
                                for(int m=0;m<s[3].size();m++){
                                    string s4=s[3];
                                    temp+=s4[m];
                                    ans.push_back(temp);
                                    temp.pop_back();
                                }
                            }
                            if (s.size() > 3) temp.pop_back();
                        }
                    }
                    if (s.size() > 2) temp.pop_back();
                }
            }
            if (s.size() > 1) temp.pop_back();
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
        check(s,temp,ans,n);
        return ans;
    }
};