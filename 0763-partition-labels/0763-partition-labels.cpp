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
        // unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            end = max(end,t[s[i]-'a']);//abhi tak jo bhi char aa rhaa usme se sabse last me kaun sa finish ho rhaa
            if(i==end){
                // and jab end(sabse last finish pe reach ) kar jaaye then that's the length of the partition
                ans.push_back(end-start+1);
                start=end+1;
            }
        }
        return ans;
    }
};