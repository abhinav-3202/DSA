class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>mpp;
        unordered_map<int,int>mpp1;
        for(int i = 0 ; i<s.size();i++){
            mpp[s[i]]++;
        }
        for(int i = 0 ;i<t.size();i++){
            mpp1[t[i]]++;
        }
        if(mpp!=mpp1) return false;
        return true;
    }
};