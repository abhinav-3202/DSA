class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        map<vector<int>,int>mpp;
        vector<int>temp;
        for(int i=0;i<n-3;i++){
            temp.push_back(nums[i]);
            for(int j=i+1;j<n-2;j++){
                temp.push_back(nums[j]);
                for(int k=j+1;k<n-1;k++){
                    temp.push_back(nums[k]);
                    for(int m=k+1;m<n;m++){
                        if(m+1<n &&nums[m]==nums[m+1]){
                            continue;
                        }
                        long long req=(long long)target -nums[i]-nums[j]-nums[k];
                        if(req==nums[m]){
                            temp.push_back(nums[m]);
                            mpp[temp]++;
                            temp.pop_back();
                        }
                    }
                    temp.pop_back();
                }
                temp.pop_back();
            }
            temp.pop_back();
        }
        for(auto it:mpp){
            ans.push_back(it.first);
        }
        return ans;
    }
};