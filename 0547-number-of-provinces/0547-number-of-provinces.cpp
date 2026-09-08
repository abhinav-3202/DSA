class Solution {
public:
    void check(int i,int n,vector<bool>&vis,vector<vector<int>>& isConnected){
        vis[i]=true;
        for(int j=0;j<n;j++){
            // if vis[j]==false is ture then the remaining is unvisted then visit else it has been covered
            //If city j is already visited, then DFS has already explored the entire connected component reachable from j, so we don't need to explore j again
            if(isConnected[i][j]==1 && !vis[j]){
                check(j,n,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n = isConnected.size();
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                check(i,n,vis,isConnected);
            }
        }
        return count;
    }
};