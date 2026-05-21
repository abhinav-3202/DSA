class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n = matrix[0].size();
        stack<pair<int,int>>st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0) st.push({i,j});
            }
        }
        while(!st.empty()){
            int a = st.top().first;
            int b = st.top().second;
            st.pop();
            for(int i =0;i<m;i++){
                matrix[i][b]=0;
            }
            for(int j =0;j<n;j++){
                matrix[a][j]=0;
            }
        }
        return ;
    }
};