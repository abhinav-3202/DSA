class Solution {
public:
    vector<vector<int>>ans;
    void check(int i,vector<int>&temp,int k ,int n, int count,int sum){
        if(count == k && sum==n) {
            ans.push_back(temp);
            return;
        }
        // if(i==nums.size()) return ;
        if(sum > n || count == k || i>9 ) return;
        temp.push_back(i);
        check(i+1,temp,k,n,count+1,sum+i);
        temp.pop_back();
        check(i+1,temp,k,n,count,sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        int count = 0 ;
        int sum = 0;
        check(1,temp,k,n,count,sum);
        return ans;
    }
};