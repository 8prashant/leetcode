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
    unordered_map<int,TreeNode*> m;
    unordered_map<int,TreeNode*> p;
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin.tie(nullptr);
        if(d.size()==0){
            return NULL;
        }
        TreeNode *newnode= new TreeNode{d[0][0]};
        TreeNode* root=newnode;
        m[d[0][0]]=newnode;
        for(int i=0;i<d.size();i++){
            if(m.find(d[i][0])==m.end() && m.find(d[i][1])==m.end()){
                TreeNode* newnode= new TreeNode{d[i][0]};
                TreeNode* newnode2=new TreeNode{d[i][1]};
                p[d[i][1]]=newnode;
                m[d[i][0]]=newnode;
                m[d[i][1]]=newnode2;
                if(d[i][2]==1){
                    newnode->left=newnode2;
                }
                else{
                    newnode->right=newnode2;
                }

            }
            else if(m.find(d[i][0])!=m.end() && m[d[i][0]]!=NULL && m.find(d[i][1])==m.end()){
                TreeNode* newnode= new TreeNode{d[i][1]};
                p[d[i][1]]=m[d[i][0]];
                m[d[i][1]]=newnode;
                if(d[i][2]==1){
                    m[d[i][0]]->left=newnode;
                }
                else{
                    m[d[i][0]]->right=newnode;
                }
            }
            else if(m.find(d[i][0])==m.end() && m.find(d[i][1])!=m.end() && m[d[i][1]]!=NULL){
                TreeNode* newnode= new TreeNode{d[i][0]};
                p[d[i][1]]=newnode;
                m[d[i][0]]=newnode;
                if(d[i][2]==1){
                    newnode->left=m[d[i][1]];
                }
                else{
                    newnode->right=m[d[i][1]];
                }
            }
            else if(m.find(d[i][0])!=m.end() && m[d[i][0]]!=NULL && m.find(d[i][1])!=m.end() && m[d[i][1]]!=NULL){       
                if(d[i][2]==1){
                    m[d[i][0]]->left=m[d[i][1]];
                }
                else{
                    m[d[i][0]]->right=m[d[i][1]];
                }
                p[d[i][1]]=m[d[i][0]];
            }
        }
        if(p.find(root->val)!=p.end()){
                cout<<"yes"<<endl;
                TreeNode* curr=root;
                while(p.find(curr->val)!=p.end()){
                    cout<<"p="<<curr->val<<endl;
                    curr=p[curr->val];
                }
                root=curr;
        }
        return root;
    }
};