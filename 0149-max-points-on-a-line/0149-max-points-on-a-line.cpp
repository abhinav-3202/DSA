class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxi=INT_MIN;
        if(points.size()==1) return 1;
        for(int i=0;i<points.size();i++){
            int y=points[i][1];
            int x=points[i][0];
            unordered_map<double,int>mpp;
            for(int j=0;j<points.size();j++){
                if(j!=i && x!=points[j][0]){
                    double slope= 1.0*(y-points[j][1])/(x-points[j][0]);
                    mpp[slope]++;
                    maxi=max(maxi,mpp[slope]);
                }
                else if(j!=i && x==points[j][0]){
                    mpp[INT_MIN]++;
                    maxi=max(maxi,mpp[INT_MIN]);
                }
            }
        }
        return maxi+1;
    }
};