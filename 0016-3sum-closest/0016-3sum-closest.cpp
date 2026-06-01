class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int close=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            // if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==target) return target;
                if(abs(close-target)>abs(target-sum)){
                    close=sum;
                }
                if(sum>target) {
                    // maxi=max(sum,maxi);
                    k--;
                }
                else{
                    // mini=min(sum,mini);
                    j++;
                }
                // while(j<k&&nums[j]==nums[j+1]) j++;
                // while(j<k&&nums[k]==nums[k-1]) k--;
            }
        }
        return close; 
    }
};