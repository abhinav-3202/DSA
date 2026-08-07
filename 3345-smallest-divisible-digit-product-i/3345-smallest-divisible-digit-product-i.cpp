class Solution {
public:
    bool check(int i,int t){
        int dig = 1;
        while(i>0){
            dig = dig*(i%10);
            i=i/10;
        }
        if(dig%t==0) return true;
        return false;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            if(check(i,t)) return i;
        }
        return 1;
    }
};