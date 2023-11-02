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
    pair<int,int> check(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> lp=check(root->left) , rp=check(root->right);

        int ls=lp.first,rs=rp.first,ln=lp.second,rn=rp.second;
        if(((ls+rs+root->val)/(ln+rn+1))==root->val){
            cout<<"r="<<root->val<<endl;
            ans+=1;
        }
        return {ls+rs+root->val,ln+rn+1};

    }
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> a=check(root);
        return ans;
    }
};