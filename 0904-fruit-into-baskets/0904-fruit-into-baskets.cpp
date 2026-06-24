class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0;
        int maxi =0;
        int count =0;
        unordered_map<int,int>mpp;
        while(r<fruits.size()){
            if(mpp.find(fruits[r]) == mpp.end()){
                count++;
            }
            mpp[fruits[r]]++;
            while( count > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);
                    count--;
                }
                l++;
            }
            if(count<=2){
                maxi = max(maxi,r-l+1);
            }
            // maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};