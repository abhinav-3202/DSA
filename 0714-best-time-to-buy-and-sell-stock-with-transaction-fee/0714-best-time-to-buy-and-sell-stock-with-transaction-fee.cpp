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
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        vector<vector<int>>dp(n+1,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int count=1;count>=0;count--){
                int profit;
                if(count==0){
                    int buy=-prices[i]+dp[i+1][1];
                    int notBuy=dp[i+1][count];
                    profit=max(buy,notBuy);
                }
                else{
                    int sell=prices[i]+dp[i+1][0]-fee;
                    int notSell=dp[i+1][count];
                    profit=max(sell,notSell);
                }
                dp[i][count]=profit;
            }
        }
        return dp[0][0];
        // return check(prices,0,n,fee,count,dp);
    }
};