class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>ans;
        int m=board.size();
        int n=board[0].size();
        vector<int> dx={-1,0,1,1,1,0,-1,-1};
        vector<int> dy={-1,-1,-1,0,1,1,1,0};
        for(int i=0;i<m;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                int live=0;
                int dead=0;
                for(int k=0;k<8;k++){
                    int a=i+dx[k];
                    int b=j+dy[k];
                    if(a>=0 && a<m && b>=0 && b<n){
                        if(board[a][b]==0){
                            dead++;
                        }
                        else live++;
                    }
                }
                if(board[i][j]==0){
                    if(live==3){
                        temp.push_back(1);
                    }
                    else temp.push_back(0);
                }
                else{
                    if(live<2) temp.push_back(0);
                    else if(live==2||live==3){
                        temp.push_back(1);
                    }
                    else if(live>3){
                        temp.push_back(0);
                    }
                    else{
                        temp.push_back(1);
                    }
                }
            }
            ans.push_back(temp);
        }
        board=ans;
    }
};