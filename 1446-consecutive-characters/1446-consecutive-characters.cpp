class Solution {
public:
    int maxPower(string s) {
        int maxi =0;
        int n=s.size();
        int i=0,j=0;
        while(j<n){
            if(s[i]==s[j]){
                maxi=max(maxi,j-i+1);
                j++;
            }
            else{
                i=j;
            }
        }
        return maxi;
    }
};