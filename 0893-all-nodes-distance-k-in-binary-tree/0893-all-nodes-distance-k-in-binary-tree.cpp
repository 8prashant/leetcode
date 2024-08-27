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
    unordered_map<TreeNode*,TreeNode*>m;
    void check(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL){
            m[root->left]=root;
            check(root->left);
        }
        if(root->right!=NULL){
            m[root->right]=root;
            check(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0){
            return {target->val};
        }
        check(root);
        queue<pair<TreeNode*,int>>q;
        q.push({target,k});
        set<TreeNode*>s;
        vector<int>ans;
        while(!q.empty()){
            int si=q.size();
            for(int i=0;i<si;i++){
                pair<TreeNode*,int>p=q.front();
                q.pop();
                TreeNode* node=p.first;
                int value=p.second;
                cout<<node->val<<" "<<value<<endl;
                s.insert(node);
                if(value==0){
                    ans.push_back(node->val);
                    continue;
                }
                if(node->left && s.find(node->left)==s.end()){
                    q.push({node->left,value-1});
                }
                if(node->right && s.find(node->right)==s.end()){
                    q.push({node->right,value-1});
                }
                if(m.find(node)!=m.end() && s.find(m[node])==s.end()){
                    q.push({m[node],value-1});
                }
            }
            // cout<<endl;
        }
        return ans;
    }
};