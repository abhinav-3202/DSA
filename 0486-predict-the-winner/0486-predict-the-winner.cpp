class Solution {
public:
    // bool ans = false;
    bool check(vector<int>&nums,int i , int j,int oneScore,int twoScore,bool choose ){
        // if(ans == true) return ;
        if(i>j) {
            return oneScore >= twoScore;
        }
        if(choose){
            bool left = check(nums,i+1,j,oneScore+nums[i],twoScore,false);
            
            bool right = check(nums,i,j-1,oneScore+nums[j],twoScore,false);
            return left||right;
            //either of the path se win mil jaaye
        }
        else{
            bool left = check(nums,i+1,j,oneScore,twoScore+nums[i],true);
            bool right = check(nums,i,j-1,oneScore,twoScore+nums[j],true); 
            return left && right;
            // && isliye liya h because p2 tabhi jeetega jab dono path se usko win milega
        }
        // if(ans==true) return
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int oneScore=0;
        int twoScore=0;
        bool choose = true;
        return check(nums,i,j,oneScore,twoScore,choose);
        // return ans;
    }
};