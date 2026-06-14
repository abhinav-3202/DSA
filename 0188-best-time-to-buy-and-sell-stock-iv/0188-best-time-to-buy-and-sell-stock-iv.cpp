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
        vector<vector<int>>dp(n,vector<int>(2*k,-1));
        return check(k,prices,0,n,count,dp);
    }
};