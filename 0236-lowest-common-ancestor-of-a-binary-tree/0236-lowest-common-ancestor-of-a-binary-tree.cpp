/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    bool check(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return false;
        }
        bool left=check(root->left,p,q);
        bool right=check(root->right,p,q);
        if(root==p || root==q){
            if(left==true || right==true){
                ans=root;
                return false;
            }
            else{
                return true;
            }
        }
        if(left==true && right==true){
            ans=root;
        }
        return left||right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        check(root,p,q);
        return ans;
    }
};