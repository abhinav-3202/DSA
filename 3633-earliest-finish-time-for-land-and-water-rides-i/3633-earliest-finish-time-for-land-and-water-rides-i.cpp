class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m=landStartTime.size();
        int n=waterStartTime.size();
        int mini=INT_MAX;
        int ans = INT_MAX;
        for(int i=0;i<m;i++){
            int start = landStartTime[i]+landDuration[i];
            for(int j=0;j<n;j++){
                int end = INT_MAX;
                if(start>=waterStartTime[j]){
                    end = start+waterDuration[j];
                }
                else{
                    end =waterDuration[j]+waterStartTime[j];
                }
                mini = min(mini,end);
            }
            ans = min(mini,ans);
        }
        mini = INT_MAX;
        for(int j=0;j<n;j++){
            int start=waterStartTime[j]+waterDuration[j];
            for(int i=0;i<m;i++){
                int end = INT_MAX;
                if(start>=landStartTime[i]){
                    end = start+ landDuration[i];
                }
                else {
                    //here i was doing mistake was i was adding the start also , but there is no need to add start as the time is going on , so adding start will double it .
                    //simply add the startTime and endTime that will be the finish time 
                    end =landDuration[i]+landStartTime[i];
                }
                mini = min(mini,end);
            }
            ans = min(mini,ans);
        }
        return ans;
    }
};