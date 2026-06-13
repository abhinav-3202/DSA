class Solution {
public:
    int check(vector<int>&prices,int i,int n,int count,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(count==4) return 0;
        if(dp[i][count]!=-1) return dp[i][count];
        int profit;
        if(count%2==0){
            int buy=-prices[i]+check(prices,i+1,n,count+1,dp);
            int notBuy = check(prices,i+1,n,count,dp);
            profit=max(buy,notBuy);
        }
        else{
            int sell = prices[i]+check(prices,i+1,n,count+1,dp);
            int notSell = check(prices,i+1,n,count,dp);
            profit=max(sell,notSell);
        }
        return dp[i][count] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int count=0;
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return check(prices,0,n,count,dp);
    }
};