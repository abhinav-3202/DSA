class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        int mini = INT_MAX;
        for(int i=0;i<nums1.size();i++){
            mpp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(mpp.find(nums2[i])!=mpp.end()){
                mini = min(mini,nums2[i]);
            }
        }
        if(mini==INT_MAX) return -1;
        return mini;
    }
};