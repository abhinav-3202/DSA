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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode*>q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL){
                flag = false;
                continue;
            }
            if(flag==false && node) return false;
            // if(node->left==NULL&&node->right==NULL) {
            //     continue;
            // }
            // ek baar NULL push ho gya uske baad kuch bhi aaye level me wo to flase hi hoga
            
            q.push(node->left);
            q.push(node->right);
        }
        return true;
    }
};