class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i =0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<vector<int>>bucket(n+1);
        // for a single frequency multiple element can be their so bucket must be 2D array
        // here n+1 or the indexes represents frequency , the maximum possible frequency
        for(auto it:mpp){
            int el = it.first;
            int freq = it.second;
            bucket[freq].push_back(el);
        }
        vector<int>ans;
        int count=0;
        for(int i=n;i>=0;i--){
            // here we are doing for every element on that particlular frequency push them all 
            for(int el : bucket[i]){
                ans.push_back(el);
            }
            if(ans.size()==k) return ans;
        }
        return ans;
    }
};