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
    unordered_map<TreeNode*,TreeNode*>m;
    int n=0;
    void check(TreeNode* root){
        if(root->left!=NULL){
            m[root->left]=root;
            check(root->left);
        }
        if(root->right!=NULL){
            m[root->right]=root;
            check(root->right);
        }
    }
    TreeNode* t=NULL;
    void find(int tar,TreeNode* root){
        n=max(n,root->val);
        if(root->val==tar){
            t=root;
        }
        if(root->left!=NULL){
            find(tar,root->left);
        }
        if(root->right!=NULL){
            find(tar,root->right);
        }
    }
    int amountOfTime(TreeNode* root, int target) {
        check(root);
        find(target,root);
        queue<TreeNode*>q;
        q.push(t);
        int ans=0;
        vector<int>v(n+1,-1);
        while(!q.empty()){
            ans++;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* f=q.front();
                q.pop();
                v[f->val]=1;
                if(f->left!=NULL && v[f->left->val]==-1){
                    q.push(f->left);
                }
                if(f->right!=NULL && v[f->right->val]==-1){
                    q.push(f->right);
                }
                if(m.find(f)!=m.end() && v[m[f]->val]==-1){
                    q.push(m[f]);
                }
            }
            
        }
        return ans-1;
    }
};