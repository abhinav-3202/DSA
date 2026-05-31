class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n=asteroids.size();
        long long mas=mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i=0;i<n;i++){
            if(mas<asteroids[i]) return false;
            else{
                mas+= asteroids[i];
            }
        }
        return true;
    }
};