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
    int ans=0;
    void dfs(TreeNode* root,int ma,int mi){
        int a=root->val;
        ans=max(ans,abs(ma-a));
        ans=max(ans,abs(mi-a));
        ma=max(ma,root->val);
        mi=min(mi,root->val);
        if(root->left!=NULL){
            dfs(root->left,ma,mi);
        }
        if(root->right!=NULL){
            dfs(root->right,ma,mi);
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root,root->val,root->val);
        return ans;
    }
};