class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        int end=0;
        unordered_map<int,int>mppp;
        vector<int>ans;
        for(int i =0;i<s.size();i++){
            mppp[s[i]]++;
            bool flag = true;
            for(auto it:mppp){
                if(mpp[it.first]!=it.second){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                mppp.clear();
                ans.push_back(i-end+1);
                end=i+1;
            }
        }
        return ans;
    }
};