class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,int>mpp;
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]==nums2[j]){
                if(mpp.find(nums1[i])==mpp.end()){
                    ans.push_back(nums1[i]);
                    mpp[nums1[i]]++;
                }
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j]) j++;
            else if(nums1[i]<nums2[j]) i++;
        }
        return ans;
    }
};