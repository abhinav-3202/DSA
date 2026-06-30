class Solution {
public:
    int check(vector<int>&nums,int i,int j,int n,int state,vector<vector<int>>&dp){
        if(j==n) return 0;
        if(dp[i][state]!=-1) return dp[i][state];
        int curState;
        if(nums[j]-nums[i]>0){
            curState=1;
        }
        else if(nums[j]==nums[i]){
            curState=0;
        }
        else curState=2;
        if(curState!=0 && state!=curState){
            // int pick=1+check(nums,i+1,j+1,n,curState);
            // i was doing mistake here that i+1 will be just next element , suppose j has moved to some index doing i+1 will make it wrong
            int pick=1+check(nums,j,j+1,n,curState,dp);
            int notPick=check(nums,i,j+1,n,state,dp);
            return dp[i][state]=max(pick,notPick);
        }
        else{
            return dp[i][state]=check(nums,i,j+1,n,state,dp);
        }
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        if(n==2) {
            if(nums[1]!=nums[0]) return 2;
            else return 1;
        }
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return 1+check(nums,0,1,n,3,dp);
        // not handling the equal wala case
    }
};