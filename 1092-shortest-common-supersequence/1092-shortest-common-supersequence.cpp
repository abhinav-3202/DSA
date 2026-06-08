class Solution {
public:
    void rev(string &s){
        int i =0;
        int j=s.size()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        if(str1==str2&&str1.size()==str2.size()) return str1;
        int m=str1.size();
        int n=str2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=m;
        int j=n;
        string ans="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=str1[i-1];
                i--;
            }
            else{
                ans+=str2[j-1];
                j--;
            }
        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans+=str2[j-1];
            j--;
        }
        rev(ans);
        return ans;
    }
};