class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<int,int>mpp;
        for(int i = 0 ; i<s.size();i++){
            mpp[s[i]]++;
        }
        int sum = 0 ;
        unordered_map<int,int>vis;
        for(int i = 0 ;i<s.size();i++){
            if(vis.find(s[i])!=vis.end()){
                continue;
            }
            if(s[i]<=57 && s[i]>=48){
                int f=s[i]-48;
                if(mpp.find(57-f)!= mpp.end()){
                    sum+=abs(mpp[s[i]]-mpp[57-f]);//suppose a=3 times an z = 1 time and then never visit them
                    vis[57-f]++;
                }
                else{
                    sum+= mpp[s[i]];
                }
            }
            else{
                int f = s[i]-97;
                if(mpp.find(122-f)!=mpp.end()){
                    sum+=abs(mpp[s[i]]-mpp[122-f]);
                    vis[122-f]++;
                }
                else sum+= mpp[s[i]];
            }
            vis[s[i]]++;
        }
        return sum;
    }
};