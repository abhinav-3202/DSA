class Solution {
public:
    int check(vector<int>&coins,vector<vector<int>>&dp,int amount,int i){
        if(i<0) return INT_MAX;
        else if(amount==0) return 0;
        else if(i==0){
            if(amount% coins[0]==0) return amount/coins[0];
            else return INT_MAX;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int notTake = check(coins,dp,amount,i-1);
        int take = INT_MAX;
        // if(coins[i]<=amount) take = 1 + check(coins,dp,amount-coins[i],i); // here it was crashing because what if take gets INT_MAX and adding 1 to it is causing integer overflow.
        if(coins[i]<=amount) {
            int result=check(coins,dp,amount-coins[i],i);
            if(result!=INT_MAX) take = 1 + result;
        }
        return dp[i][amount] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // int res = check(coins,dp,amount,n-1);
        // if(res==INT_MAX) return -1;
        // else return res;
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        // impossible to make sum with 0 available coins
        for(int j=1;j<=amount;j++){
            dp[0][j]=INT_MAX;
        }
        // vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX)); // 
        // // dp[0][0]=0;
        // for(int i=0;i<=n;i++){
        //     dp[i][0]=0;
        // } //it takes 0 coins to make sum = 0 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                int notTake = dp[i-1][j];
                int take = INT_MAX;
                if(coins[i-1]<=j) { 
                    int result = dp[i][j-coins[i-1]];
                    if(result!=INT_MAX) take=1+result;
                }
                dp[i][j]=min(take,notTake);
            }
        }
        if(dp[n][amount]==INT_MAX) return -1;
        return dp[n][amount];
    }   
};