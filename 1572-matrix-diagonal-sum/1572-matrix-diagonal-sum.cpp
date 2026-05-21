class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int i=0,j=0,k=n-1;
        int sum =0;
        bool flag = false;
        while(i!=n){
            if(n%2==0){
                sum+= mat[i][j]+mat[i][k];
                if(i==n/2-1){

                }
                else if(i>=n/2){
                    j--;
                    k++;
                }
                else if(i<n/2){
                    j++;
                    k--;
                }
                i++;
            }
            else{
                if(j==k){
                    sum+= mat[i][j];   
                }
                else{
                    sum+= mat[i][j]+mat[i][k];
                }
                if(i>=n/2){
                    j--;
                    k++;
                }
                else if(i<n/2){
                    j++;
                    k--;
                }
                i++;
            }
        }
        return sum;
    }
};