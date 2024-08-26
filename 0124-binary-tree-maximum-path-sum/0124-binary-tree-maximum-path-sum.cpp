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
    int ans=INT_MIN;
    int check(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int l=check(root->left);
        int r=check(root->right);
        ans=max(ans,root->val+l+r);
        ans=max(ans,root->val+max(l,r));
        ans=max(ans,root->val);
        return max(root->val+max(l,r),root->val);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        check(root);
        return ans;
    }
};