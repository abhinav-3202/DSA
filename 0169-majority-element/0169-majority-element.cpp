class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int count = 0;
        // if the choosen elemnt will be majority element then it would not have been cancelled or the count come to 0....
        // hence at the last u will always get the majority element because its count will never be 0
        for(int i =0;i<nums.size();i++){
            if(count==0) ans = nums[i];
            if(nums[i]==ans){
                count++;
            }
            else count--;
        }
        return ans;
    }
};