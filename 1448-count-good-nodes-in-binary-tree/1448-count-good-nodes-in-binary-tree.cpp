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
    void check(TreeNode* root,int& count,int maxi){
        if(root==NULL) return;
        if(root->val>=maxi){
            count++;
            check(root->left,count,root->val);
            check(root->right,count,root->val);
        }
        else{
            check(root->left,count,maxi);
            check(root->right,count,maxi);
        }
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        check(root,count,root->val);
        return count;
    }
};