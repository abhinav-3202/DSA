class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> s=strs;
        int n=strs.size();
        unordered_map<string,vector<string>>mpp;
        for(int i=0;i<n;i++){
            sort(s[i].begin(),s[i].end());
            mpp[s[i]].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};