class Solution {
public:
    int reverse(int val){
        int revNo = 0;
        while(val>0){
            int last = val%10;
            val = val/10;
            revNo = revNo*10 + last;
        }
        return revNo;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int ans = INT_MAX;
        for(int i = 0 ; i < nums.size();i++){
            int val = reverse(nums[i]);
            if (mpp.find(nums[i]) != mpp.end()) {
                ans = min(ans, i - mpp[nums[i]]);
            }

            // Always UPDATE to latest index (don't skip if exists)
            mpp[val] = i;
        }
        return ans==INT_MAX ? -1 : ans;
    }
};