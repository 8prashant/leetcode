class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m=graph.size(),n=graph[0].size();
        vector<vector<int>> adj(m);
        for(int i=0;i<m;i++){
            for(auto x:graph[i]){
                adj[x].push_back(i);
            }
        }
        vector<int> d(m,0);
        queue<int>q;
        for(int i=0;i<m;i++){
            d[i]=graph[i].size();
            if(d[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int a=q.front();
            ans.push_back(a);
            q.pop();
            for(auto x:adj[a]){
                d[x]-=1;
                if(d[x]==0){
                    q.push(x);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};