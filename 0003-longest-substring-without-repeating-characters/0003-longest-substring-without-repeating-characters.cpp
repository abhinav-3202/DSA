class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0,maxi=0;
        int n=s.size();
        unordered_map<int,int>mpp;
        while(i<n&&j<n){
            while(mpp.find(s[j])!=mpp.end()){
                    mpp[s[i]]--;
                    if(mpp[s[i]]==0){
                        mpp.erase(s[i]);
                        i++;
                    }
            }
            maxi=max(maxi,j-i+1);
            mpp[s[j]]++;
            j++;
        }
        return maxi;
    }
};