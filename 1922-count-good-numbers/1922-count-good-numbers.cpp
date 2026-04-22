class Solution {
public:
    long long MOD = 1000000007;
    long long power(long long a,long long n){
        long long ans = 1;
        a = a % MOD;
        while(n>0){
            if(n%2!=0){
                ans = (ans*a)%MOD;
            }
            a = (a * a) % MOD;
            n = n/2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        if(n%2==0){
            long long a = power(5,n/2);
            long long b = power(4,n/2);
            return (a*b) % MOD;
        }
        else{
            long long a = power(5,n/2+1);
            long long b = power(4,n/2);
            return (a*b) % MOD;
        }
        return 1;
    }
};