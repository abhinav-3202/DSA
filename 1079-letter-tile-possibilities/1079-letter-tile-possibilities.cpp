class Solution {
public:
    int ans=0;
    void check(string &tiles,vector<bool>&vis,int n){
        for(int i=0;i<n;i++){
            if(vis[i]==true) continue;
            if(i>0&&tiles[i-1]==tiles[i]&&!vis[i-1]){  //in notes better explain
                continue;
            }
            vis[i]=true;//is beign used in forming string 
            ans++;
            check(tiles,vis,n);
            vis[i]=false; // all combinations formed containing this current letter
        }
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        int n=tiles.size();
        vector<bool>vis(n,false);
        check(tiles,vis,n);
        return ans;
    }
};