class Solution {
public:
    int check(int n ,int k){
        if(n==1) return 0;//agar 1 hi person h then wo hi winner hoga 
        // we got the winner now adding people would shift the indexing so , now fix it 
        return (check(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        return check(n,k)+1;
    }
};