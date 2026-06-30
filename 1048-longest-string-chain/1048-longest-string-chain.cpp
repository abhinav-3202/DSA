class Solution {
public:
    bool compare(string& a , string& b){
        int m=a.size();
        int n=b.size();
        if(m+1!=n) return false;
        int i=0,j=0,count=0;
        while(i<m){
            if(count>1) return false;
            if(a[i]!=b[j]){
                count++;
                j++;
            }
            else {
                i++;
                j++;
            }
        }
        return true;
    }
    int check(int i,int prev,int n,vector<string>&words,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        if(prev+1==0 || compare(words[prev],words[i])){
            int pick=1+check(i+1,i,n,words,dp);
            int notPick=check(i+1,prev,n,words,dp);
            return dp[i][prev+1]=max(pick,notPick);
        }
        else{
            return dp[i][prev+1]=check(i+1,prev,n,words,dp);
        }
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[]( string& a , string& b){
            return a.length()<b.length();
        });
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return check(0,-1,n,words,dp);
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(compare(words[prev],words[i]) && dp[prev]+1>dp[i]){
                    dp[i]=1+dp[prev];
                    maxi=max(maxi,dp[i]);
                }
            }
        }
        return maxi;
    }
};