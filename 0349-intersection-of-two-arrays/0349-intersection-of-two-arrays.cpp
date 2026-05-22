class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,int>mpp;
        for(int i =0;i<n;i++){
            mpp[nums1[i]]++;
        }
        for(int j=0;j<m;j++){
            if(mpp.find(nums2[j])!=mpp.end()){
                ans.push_back(nums2[j]);
                mpp.erase(nums2[j]);
            }
        }
        return ans;
    }
};