class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> s=strs;
        int n=strs.size();
        for(int i=0;i<n;i++){
            sort(s[i].begin(),s[i].end());
        }
        vector<vector<string>>ans;
        vector<bool>check(n,false);
        for(int i=0;i<n;i++){
            vector<string>temp;
            if(check[i]==true) continue;
            temp.push_back(strs[i]);
            check[i]=true;
            string c=s[i];
            for(int j=i;j<n;j++){
                if(check[j]==true) continue;
                if(s[j]==c){
                    temp.push_back(strs[j]);
                    check[j]=true;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};