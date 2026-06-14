class Solution {
public:
    int check(vector<int>&prices,int i,int n,int flag,vector<vector<int>>&dp){
        if(i>=n) return 0;
        int profit;
        if(dp[i][flag]!=-1) return dp[i][flag];
        if(flag==1){
            int buy=-prices[i]+check(prices,i+1,n,0,dp);
            int notBuy=check(prices,i+1,n,1,dp);
            profit=max(buy,notBuy);
        }
        else{
            int sell=prices[i]+check(prices,i+2,n,1,dp);
            int notSell= check(prices,i+1,n,0,dp);
            profit=max(sell,notSell);
        }
        return dp[i][flag]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int flag=1;
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return check(prices,0,n,flag,dp);
    }
};