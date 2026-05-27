class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==1) return 0;
        int jump = 0;
        int maxReach = 0 ;
        int boundary = 0;
        for(int i=0;i<nums.size();i++){
            maxReach = max(maxReach,i+nums[i]);
            if(i==boundary){
                boundary = maxReach;
                jump++;
            }
            if(boundary>=n-1) break;
        }
        return jump;
    }
};