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
    void find(vector<int>temp,int &ans){
        int n=temp.size();
        int val=temp[0];
        for(int i=1;i<n;i++){
            val=val*10+temp[i];
        }
        ans+=val;
    }
    void check(TreeNode* root,vector<int>&temp,int& ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            temp.push_back(root->val);
            find(temp,ans);
            // temp.pop_back();
            return;
        }
        temp.push_back(root->val);
        if(root->left){
            check(root->left,temp,ans);
            temp.pop_back();
        }
        if(root->right){
            check(root->right,temp,ans);
            temp.pop_back();
        }
    }
    int sumNumbers(TreeNode* root) {
        vector<int>temp;
        int ans=0;
        // temp.push_back(root->val);
        check(root,temp,ans);   
        return ans;
    }
};