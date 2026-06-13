class Solution {
public:
    int check(vector<int>&prices,int i,int n,int flag,int count,vector<vector<vector<int>>>&dp){
        if(i==n) return 0;
        if(count==2) return 0;
        if(dp[i][flag][count]!=-1) return dp[i][flag][count];
        int profit;
        if(flag==1){
            int buy=-prices[i]+check(prices,i+1,n,0,count,dp);
            int notBuy = check(prices,i+1,n,1,count,dp);
            profit=max(buy,notBuy);
        }
        else{
            int sell = prices[i]+check(prices,i+1,n,1,count+1,dp);
            int notSell = check(prices,i+1,n,0,count,dp);
            profit=max(sell,notSell);
        }
        return dp[i][flag][count] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int count=0;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,
        vector<int>(3,-1)));
        return check(prices,0,n,1,count,dp);
    }
};