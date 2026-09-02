class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int>mpp;
        unordered_map<int,int>mpp1;
        mpp[nums[0]]++;
        int prev=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(mpp.find(nums[i])==mpp.end()){
                mpp[nums[i]]++;
                prev=nums[i];
            }
            else {
                mpp[nums[i]]++;
                if(nums[i]==prev) continue;
                else{
                    if(mpp[nums[i]]>1){
                        mpp1[nums[i]]++;
                        prev=nums[i];
                    }
                }
            }
        }
        for(auto it:mpp1){
            if(mpp.find(it.first)!=mpp.end()){
                mpp.erase(it.first);
            }
        }
        return mpp.size();
    }
};