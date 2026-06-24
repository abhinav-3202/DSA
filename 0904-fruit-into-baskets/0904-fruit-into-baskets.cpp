class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i =0,maxi=0;
        int n=fruits.size();
        unordered_map<int,int>mpp;
        for(int j=0;j<n;j++){
            if(mpp.find(fruits[j])==mpp.end()&&mpp.size()==2){
                while(mpp.size()==2){
                    mpp[fruits[i]]--;
                    if(mpp[fruits[i]]==0){
                        mpp.erase(fruits[i]);
                    }
                    i++;
                }
            }
            mpp[fruits[j]]++;
            maxi=max(maxi,j-i+1);
        }
        return maxi;
    }
};