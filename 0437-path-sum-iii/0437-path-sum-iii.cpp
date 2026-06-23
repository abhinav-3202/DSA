/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;
    void check(TreeNode* root,int targetSum ,long long sum,unordered_map<long long,int>&mpp){
        if(root==NULL) return;
        sum+=(long long)root->val;
        if(mpp.find(sum - (long long)targetSum)!=mpp.end()){
            // count++;
            // here i was doing wrong,there can be multiple instances of sum like [0,1,1] so count stores the frequency of occurence of sum
            count+=mpp[sum-(long long)targetSum];
        }
        mpp[sum]++;
        check(root->left,targetSum,sum,mpp);
        check(root->right,targetSum,sum,mpp);
        // if(sum==targetSum) count++; this cannot tell whether previously the sum was possible ot not 
        
        mpp[sum]--;// backtrack kar rhee then wo currentSum wala to nikal jaa rha , then agar uski freq 0 h then eraase that instance in mpp 
        if(mpp[sum]==0){
            mpp.erase(sum);
        }//kisi ki frequeny agar 0 ho gyi then remove 
    }
    int pathSum(TreeNode* root, int targetSum) {
        // keep track of currentSum and previous sum , if like that exist in map then mostly there exist a path between the two nodes
        unordered_map<long long,int>mpp;
        mpp[0]=1;
        long long sum = 0 ;
        check(root,targetSum,sum,mpp);
        return count;
    }
};