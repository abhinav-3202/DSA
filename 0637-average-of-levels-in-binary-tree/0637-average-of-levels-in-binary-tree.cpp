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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>ans;
        // if(root==NULL) return ans;
        while(!q.empty()){
            int n=q.size();
            double sum = 0;
            for(int i=0;i<n;i++){
                TreeNode* first = q.front();
                q.pop();
                if(first->left!=NULL) q.push(first->left);
                if(first->right!=NULL) q.push(first->right);
                sum += double(first->val);
            }
            ans.push_back(sum/n);
        }
        return ans;
    }
};