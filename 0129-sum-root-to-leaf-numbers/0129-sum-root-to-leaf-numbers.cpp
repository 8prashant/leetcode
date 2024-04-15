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
    int sum=0;
    void re(TreeNode* root,int s){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            s=s*10+root->val;
            sum+=s;
            return;
        }
        s=s*10+root->val;
        re(root->left,s);
        re(root->right,s);
    }
    int sumNumbers(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin.tie(nullptr);
        if(root==NULL){
            return {};
        }
        re(root,0);
        return sum;
    }
};