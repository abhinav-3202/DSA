class Solution {
public:
    int check(vector<int>&prices,int i,int n,int fee,int count,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][count]!=-1) return dp[i][count];
        int profit;
        if(count==0){
            int buy=-prices[i]+check(prices,i+1,n,fee,1,dp);
            int notBuy=check(prices,i+1,n,fee,count,dp);
            profit=max(buy,notBuy);
        }
        else{
            int sell=prices[i]+check(prices,i+1,n,fee,0,dp)-fee;
            int notSell=check(prices,i+1,n,fee,count,dp);
            profit=max(sell,notSell);
        }
        return dp[i][count]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int count=0;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return check(prices,0,n,fee,count,dp);
    }
};