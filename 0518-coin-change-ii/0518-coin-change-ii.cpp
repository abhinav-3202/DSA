class Solution {
public:
    int check(vector<int>&coins,vector<vector<int>>&dp,int amount,int i){
        if(amount==0) return 1;
        if(i==0){
            if(amount%coins[0]==0) return 1;
            else return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int notTake = check(coins,dp,amount,i-1);
        int take = 0;
        if(coins[i]<=amount) {
            take=check(coins,dp,amount-coins[i],i);
        }
        return dp[i][amount] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int res= check(coins,dp,amount,n-1);
        return res;
    }
};