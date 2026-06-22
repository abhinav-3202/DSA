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
    vector<vector<int>>check(TreeNode* root,int tar,int sum,vector<int>&temp,vector<vector<int>>&ans){
        if(root==NULL) return ans;
        temp.push_back(root->val);
        int value=root->val+sum;
        if(value==tar&&(root->left==NULL&&root->right==NULL)){
            ans.push_back(temp);
            temp.pop_back();
            return ans;
        }
        check(root->left,tar,value,temp,ans);
        check(root->right,tar,value,temp,ans);
        temp.pop_back();
        return ans;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        // if(root==NULL) return ans;
        return check(root,targetSum,0,temp,ans);
    }
};