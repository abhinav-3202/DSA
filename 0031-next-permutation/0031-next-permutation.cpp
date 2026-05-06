class Solution {
public:
    void reverse(vector<int>& nums,int start,int end){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
        return;
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return ;
        int n = nums.size();
        int last= n-1;
        int pivot = -1;
        for(int i = n-1;i>0 ; i--){
            if(nums[i-1]<nums[i]){
                pivot = i-1;
                while(nums[last]<=nums[pivot]){
                    last--;
                }
                swap(nums[i-1],nums[last]);
                break;
            }
        }
        if(pivot == -1) reverse(nums,0,n-1);
        else reverse(nums,pivot+1,n-1);
        return ;
    }
};