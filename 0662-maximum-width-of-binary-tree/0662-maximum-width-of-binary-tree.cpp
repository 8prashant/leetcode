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
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*,size_t>>q;
        q.push_back({root,1});
        size_t ans=1;
        while(!q.empty()){
            size_t s=q.size();
            size_t l=q.front().second;
            size_t r=q.back().second;
            ans=max(ans,(r-l+1));
            for(size_t i=0;i<s;i++){
                pair<TreeNode*,size_t>p=q.front();
                q.pop_front();
                if(p.first->left){
                    q.push_back({p.first->left,2*p.second});
                }
                if(p.first->right){
                    q.push_back({p.first->right,2*p.second+1});
                }
            }
        }
        return ans;
    }
};