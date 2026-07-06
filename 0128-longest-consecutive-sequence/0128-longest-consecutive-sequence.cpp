class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mpp;
        int n=nums.size();
        // if(n==1) return 1;
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int maxi=1;
        int prev=INT_MIN;
        int count=0;
        for(auto it:mpp){
            if(prev+1==it.first){
                count++;
                maxi=max(maxi,count);
                prev=it.first;
            }
            else{
                prev=it.first;
                count=1;
            }
        }
        return maxi;
    }
};