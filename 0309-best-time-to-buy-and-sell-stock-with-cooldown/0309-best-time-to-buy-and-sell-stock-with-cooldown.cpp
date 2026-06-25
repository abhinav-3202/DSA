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
        // int flag=1;
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int flag=1;flag>=0;flag--){
                int profit;
                if(flag==1){
                    // int buy=0;/
                    // i
                    int buy=-prices[i]+dp[i+1][0];
                    int notBuy=dp[i+1][1];
                    profit=max(buy,notBuy);
                }
                else{
                    int sell=0;
                    // if(i<=n-2){
                    //     sell=prices[i]+dp[i+2][1];
                    // } this is wrong because u should be able to sell on last day
                    sell = prices[i]+dp[i+2][1];
                    int notSell= dp[i+1][0];
                    profit=max(sell,notSell);
                }
                dp[i][flag]=profit;
            }
        }
        return dp[0][1];  // dp[0][1] because 1 is the state of buying
        // return check(prices,0,n,flag,dp);
    }
};