class Solution {
public:
    int falseCount=0;
    void check(vector<bool>&vis,int x,int k,int i,int n){
        if(falseCount == (n-1)) return;
        if(vis[i%n]==false) check(vis,x,k,i+1,n);
        else{
            x = x+1;
            if(x==k){
                vis[i%n] = false;
                x = 0;
                falseCount++;
                check(vis,x,k,i+1,n);
            }
            else{
                check(vis,x,k,i+1,n);
            }
        }
        return ;
    }
    int findTheWinner(int n, int k) {
        vector<bool>vis(n,true);
        int x = 0;
        check(vis,x,k,0,n);
        int ans =-1;
        for(int i = 0 ; i<vis.size();i++){
            if(vis[i]==true){
                ans = i;
                break;
            }
        }
        return ans+1;
    }
};