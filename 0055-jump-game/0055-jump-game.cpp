class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            sum=i+nums[i];
            maxi=max(maxi,sum);
            if(maxi<=i) return false;
        }
        if(maxi>=n-1) return true;
        return true;
    }
};