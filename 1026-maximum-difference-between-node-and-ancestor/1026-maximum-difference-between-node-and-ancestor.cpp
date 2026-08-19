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
    void check(TreeNode* root,int maxi,int mini, int& ans){
        if(root==NULL) return;
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        int res=abs(maxi-mini);
        ans=max(ans,res);
        if(root->left){
            check(root->left,maxi,mini,ans);
        }
        if(root->right){
            check(root->right,maxi,mini,ans);
        }
        return;
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int ans=0;
        check(root,maxi,mini,ans);
        return ans;
    }
};