class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi = 0;
        int n=nums.size();
        int i=0,count=0;
        for(int j=0;j<n;j++){
            if(nums[j]==0){
                count++;
                while(count>k){
                    if(nums[i]==0){
                        count--;
                    }
                    i++;
                }
            }
            maxi=max(maxi,j-i+1);
        }
        return maxi;
    }
};