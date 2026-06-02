class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>t(26,0);
        vector<int>ans;
        int n=s.size();
        for(int i=0;i<n;i++){
            t[s[i]-'a']=i;
            // storing the last index of every char
        }
        int start=0;
        int end=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]-'a']=i;
            bool flag = true;
            for(auto it:mpp){
                if(it.second!=t[it.first]){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                mpp.clear();
                ans.push_back(i-end+1);
                end=i+1;
            }
        }
        return ans;
    }
};