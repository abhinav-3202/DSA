class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>>ans;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int j = 0;j<n;j++){
            vector<int>anss;
            for(int i = 0;i<m;i++){
                // if(i==j) continue;
                // swap(matrix[i][j],matrix[j][i]);
                anss.push_back(matrix[i][j]);
            }
            ans.push_back(anss);
        }
        return ans;
    }
};