class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // map was giving TLE because iterating over duplicate elements also 
        // so better use set data structure for unique elements
        unordered_map<int,int>mpp;
        unordered_set<int>st;
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        int n=nums.size();
        for(int i =0;i<n;i++){
            mpp[nums[i]]++;
            // st.insert(nums[i]);
        }
        int count=0;
        int maxCount=0;
        for(auto it:mpp){
            int y = it.first;
            if(mpp.find(y-1)==mpp.end()){
                int count=1;
                int x=it.first+1;
                while(mpp.find(x)!=mpp.end()){
                    count++;
                    x++;
                }
                maxCount=max(count,maxCount);
            }
        }
        // for(auto it:st){
        //     if(st.find(it-1)==st.end()){
        //         int count=1;
        //         int x=it+1;
        //         while(st.find(x)!=st.end()){
        //             count++;
        //             x++;
        //         }
        //         maxCount=max(count,maxCount);
        //     }
        // }
        return maxCount;
    }
};