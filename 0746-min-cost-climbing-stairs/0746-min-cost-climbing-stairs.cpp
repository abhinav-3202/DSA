class Solution {
public:
    int check(vector<int>&cost,int i,int n,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(check(cost,i+1,n,dp),check(cost,i+2,n,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        if(n==2) return min(cost[0],cost[1]);
        return min(check(cost,0,n,dp),check(cost,1,n,dp));
    }
};