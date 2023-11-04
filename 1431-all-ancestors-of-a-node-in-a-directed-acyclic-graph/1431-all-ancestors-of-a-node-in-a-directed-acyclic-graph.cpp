class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> cp(n);
        for(int i=0;i<edges.size();i++){
            cp[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>> cc(n);
        for(int i=0;i<edges.size();i++){
            cc[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> vis(n);
        queue<int> q;
        for(int i=0;i<cp.size();i++){
            vis[i]=cp[i].size();
            if(vis[i]==0){
                q.push(i);
            }
        }
        vector<vector<int>> ans(n);
        int i=1;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(auto b:cc[a]){
                vis[b]-=1;
                if(vis[b]==0){
                    q.push(b);
                }
            }
            set<int>s;
            for(auto b:cp[a]){
                s.insert(b);
                for(auto c:ans[b]){
                    s.insert(c);
                }
            }
            for(auto b:s){
                ans[a].push_back(b);
            }
        }
        return ans;
    }
};