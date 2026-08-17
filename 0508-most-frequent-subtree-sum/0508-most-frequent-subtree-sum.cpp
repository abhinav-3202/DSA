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
    int check(TreeNode* root,unordered_map<int,int>&mpp){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL){
            mpp[root->val]++;
            return root->val;
        }
        int left=0;
        int right=0;
        if(root->left){
            left = check(root->left,mpp);
        }
        if(root->right){
            right=check(root->right,mpp);
        }
        int ans;
        ans=left+right+root->val;
        mpp[ans]++;
        return ans;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>mpp;
        check(root,mpp);
        int freq=INT_MIN;
        for(auto it:mpp){
            freq=max(freq,it.second);
        }
        vector<int>ans;
        for(auto it:mpp){
            if(it.second==freq){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};