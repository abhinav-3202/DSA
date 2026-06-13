class Solution {
public:
    int check(vector<int>&prices,int i ,int n,int flag,vector<vector<int>>&dp){
        if(i==n) return 0;
        int profit = 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        if(flag == 1){
            int buy = -prices[i] + check(prices,i+1,n,0,dp);
            int notBuy = check(prices,i+1,n,1,dp);
            profit = max(buy,notBuy);
        }
        else{
            int sell=0;
            int notSell = 0;
                // int profitt = prices[i]-prices[j];
            sell = prices[i] + check(prices,i+1,n,1,dp);
            notSell = check(prices,i+1,n,0,dp);
            profit = max(sell,notSell);
        }
        return dp[i][flag] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // int maxi = 0;
        int  flag = 1;
        int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0]=0;
        dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int profit;
                if(j == 1){
                    int buy = -prices[i] + dp[i+1][0];
                    int notBuy = dp[i+1][1];
                    profit = max(buy,notBuy);
                }
                else{
                    int sell=0;
                    int notSell = 0;
                        // int profitt = prices[i]-prices[j];
                    sell = prices[i] + dp[i+1][1];
                    notSell = dp[i+1][0];
                    profit = max(sell,notSell);
                }
                dp[i][j]=profit;
            }
        }
        return dp[0][1];
        // return maxi;
    }
};