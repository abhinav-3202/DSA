class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2) return false;
        unordered_map<int,int>mpp1;
        unordered_map<int,int>mpp2;
        for(int i=0;i<n1;i++){
            mpp1[s1[i]]++;
        }
        for(int i=0;i<n1;i++){
            mpp2[s2[i]]++;
        }
        if(mpp2==mpp1) return true;
        for(int i=n1;i<n2;i++){
            mpp2[s2[i-n1]]--;
            if(mpp2[s2[i-n1]]==0) mpp2.erase(s2[i-n1]);
            mpp2[s2[i]]++;
            if(mpp1==mpp2) return true;
        }
        return false;
    }
};