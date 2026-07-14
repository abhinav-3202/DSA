class Solution {
public:
    void check(vector<int>&temp,int& ans,unordered_map<int,int>&mpp,vector<int>& nums,int n){
        if(temp.size()==n){
            ans++;
            return;
        }
        //nums[i]%(i+1)==0||(i+1)%nums[i]==0 in this line the if condition , i is not the factor of temp variable , lets suppose nums=[1,2,3,4,5] i =3 , and tmep might be starting with nums[2]=3 as its first letter of combination .
        for(int i=0;i<n;i++){
            int currTemp=temp.size()+1;
            if(mpp[i]==0&&(nums[i]%(currTemp)==0||(currTemp)%nums[i]==0)){
                temp.push_back(nums[i]);
                mpp[i]=1;
                check(temp,ans,mpp,nums,n);
                temp.pop_back();
                mpp[i]=0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int>temp;
        unordered_map<int,int>mpp;
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        int ans=0;
        check(temp,ans,mpp,nums,n);
        return ans;
    }
};