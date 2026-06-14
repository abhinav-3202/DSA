class Solution {
public:
    int check(int k, vector<int>& prices,int i,int n ,int count,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(count==2*k) return 0;
        if(dp[i][count]!=-1) return dp[i][count];
        int profit;
        if(count%2==0){
            int buy=-prices[i]+check(k,prices,i+1,n,count+1,dp);
            int notBuy=check(k,prices,i+1,n,count,dp);
            profit=max(buy,notBuy);
        }
        else{
            int sell=prices[i]+check(k,prices,i+1,n,count+1,dp);
            int notSell=check(k,prices,i+1,n,count,dp);
            profit=max(sell,notSell);
        }
        return dp[i][count]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        // if(k%2!=0) return 0;
        int n=prices.size();
        int count=0;
        // vector<vector<int>>dp(n,vector<int>(2*k,-1));
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int count=2*k-1;count>=0;count--){
                int profit;
                if(count%2==0){
                    int buy=-prices[i]+dp[i+1][count+1];
                    int notBuy=dp[i+1][count];
                    profit=max(buy,notBuy);
                }
                else{
                    int sell=prices[i]+dp[i+1][count+1];
                    int notSell=dp[i+1][count];
                    profit=max(sell,notSell);
                }
                dp[i][count]=profit;
            }
        }
        return dp[0][0]; 
        // return check(k,prices,0,n,count,dp);
    }
};