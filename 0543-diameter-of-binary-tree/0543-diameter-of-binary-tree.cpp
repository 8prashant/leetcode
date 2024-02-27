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
    int ds=0;
    int re(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh=re(root->left);
        int rh=re(root->right);
        ds=max(ds,(lh+rh));
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        re(root);
        return ds;
    }
};