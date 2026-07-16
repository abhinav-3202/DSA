class Solution {
public:
    int range(int x , int& maxi){
        int maxii=INT_MIN;
        int mini=INT_MAX;
        while(x>0){
            int digit=x%10;
            maxii=max(maxii,digit);
            mini=min(mini,digit);
            x=x/10;
        }
        int diff=maxii-mini;
        maxi=max(maxi,diff);
        return diff;
    }
    int maxDigitRange(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mpp[i]=range(nums[i],maxi);
        }
        int ans=0;
        for(auto it:mpp){
            if(it.second==maxi){
                ans+= nums[it.first];
            }
        }
        return ans;
    }
};