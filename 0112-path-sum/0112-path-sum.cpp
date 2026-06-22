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
    bool check(TreeNode* root,int target,int sum){
        if(root==NULL) return false;
        int value = sum+root->val;
        if(value==target && (root->left==NULL&&root->right==NULL)) return true;
        return check(root->left,target,value)||check(root->right,target,value);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        return check(root,targetSum,0);
    }
};