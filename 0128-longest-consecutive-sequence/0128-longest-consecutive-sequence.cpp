class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        // if(n==1) return 1;
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int maxi=1;
        for(auto it:mpp){
            if(mpp.find(it.first-1)==mpp.end()){
                int x=it.first;
                int count=1;
                while(mpp.find(x+1)!=mpp.end()){
                    count++;
                    maxi=max(maxi,count);
                    x++;
                }
            }
        }
        return maxi;
    }
};