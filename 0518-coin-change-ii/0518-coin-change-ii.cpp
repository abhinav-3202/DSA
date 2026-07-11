class Solution {
public:
    int check(vector<int>&coins,int i,int n,int amount,vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(i>=n || amount<0) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick = check(coins,i,n,amount-coins[i],dp);
        int notPick = check(coins,i+1,n,amount,dp);
        return dp[i][amount]=pick+notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return check(coins,0,n,amount,dp);
    }
};