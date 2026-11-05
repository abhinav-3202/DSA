class Solution {
public:
    // int check(vector<vector<char>>& mat,int i,int j,int m,int n,int x,int y){
    //     if(mat[i][j]=="0") return 0;
    //     if(i+x<m && j+y<n){
    //         if((mat[i+x][j]=="1"&&mat[i][j+y]=="1"&&mat[i+x][j+y]=="1")) return 1+check(mat,i,j,m,n,x+1,y+1);`
    //     }
    //     else return 0;
    // }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0'){
                    dp[i][j]=0;
                }
                else{
                    if(i==0 || j==0) dp[i][j]=1;
                    else{
                        dp[i][j]= 1+min({
                            dp[i-1][j],
                            dp[i-1][j-1],
                            dp[i][j-1]
                        });
                    }
                    maxi=max(maxi,dp[i][j]);
                }
            }
        }
        int ans = maxi*maxi;
        return ans;
    }
};