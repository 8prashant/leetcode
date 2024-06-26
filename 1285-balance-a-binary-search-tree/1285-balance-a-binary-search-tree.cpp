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
    vector<TreeNode*>v;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL){
            inorder(root->left);
        }
        v.push_back(root);
        if(root->right!=NULL){
            inorder(root->right);
        }
    }
    TreeNode* check(int i,int j){
        if(i>j){
            return NULL;
        }
        int m=(i+j)/2;
        TreeNode* le=check(i,m-1);
        TreeNode* rig=check(m+1,j);
        v[m]->left=le;
        v[m]->right=rig;
        return v[m];
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return check(0,v.size()-1);
    }
};