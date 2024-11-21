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
    bool isSameTree(TreeNode* p, TreeNode* qt) {
        if(p==NULL && qt==NULL){
            return true;
        }
        if(p==NULL || qt==NULL){
            return false;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({p,0});
        map<int,int>m;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<TreeNode*,int>f=q.front();
                q.pop();
                m[f.second]=f.first->val;
                if(f.first->left!=NULL){
                    q.push({f.first->left,2*f.second+1});
                }
                if(f.first->right!=NULL){
                    q.push({f.first->right,2*f.second+2});
                }
            }
        }
        q.push({qt,0});
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<TreeNode*,int>f=q.front();
                q.pop();
                if(m.find(f.second)!=m.end()){
                    if(m[f.second]!=f.first->val){
                        return false;
                    }
                }
                else{
                    return false;
                }
                if(f.first->left!=NULL){
                    q.push({f.first->left,2*f.second+1});
                }
                if(f.first->right!=NULL){
                    q.push({f.first->right,2*f.second+2});
                }   
            }
        }
        return true;
    }
};