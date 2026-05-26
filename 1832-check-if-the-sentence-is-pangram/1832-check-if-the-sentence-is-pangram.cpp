class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<int,int>mpp;
        int count=0;
        for(int i =0;i<sentence.size();i++){
            if(mpp.find(sentence[i])==mpp.end()){
                count++;
            }
            mpp[sentence[i]]++;
        }
        if(count==26) return true;
        return false;
    }
};