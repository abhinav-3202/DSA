class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int i=0;
        int n=intervals.size();
        if(n==0){
            ans.push_back(newInterval);
            return ans;
        }
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        int mini=newInterval[0];
        int maxi=newInterval[1];
        vector<int>temp;
        while(i<n&&intervals[i][0]<=newInterval[1]){
            mini=min({intervals[i][0],mini});
            maxi=max({intervals[i][1],maxi});
            i++;
        }
        temp.push_back(mini);
        temp.push_back(maxi);
        ans.push_back(temp);
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};