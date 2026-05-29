class Solution {
public:
    int check(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=check(nums[i]);
        }
        sort(nums.begin(),nums.end());
        return nums[0];
    }
};