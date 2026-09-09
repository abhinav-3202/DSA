class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        int time=0;
        queue<pair<int,int>>q;
        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,-1,0,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        if(q.size()==0 && fresh==0) return 0;
        if(q.size()==0 && fresh!=0) return -1;
        while(!q.empty()&& fresh>0){
            int p=q.size();
            for(int a=0;a<p;a++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    if(i+dx[k]>=0 && i+dx[k]<m && j+dy[k]>=0 && j+dy[k]<n && grid[i+dx[k]][j+dy[k]]==1){
                        grid[i+dx[k]][j+dy[k]] = 2;
                        fresh--;
                        q.push({i+dx[k],j+dy[k]});
                    }
                }
            }
            time++;
        }
        if(fresh>0) return -1;
        return time;
    }
};