class Solution {
public:
    int check(int x,int m,vector<int> adj[], vector<int>& q,vector<int>& ans,vector<int> rq){
        if(ans[x]!=-1){
            return q[ans[x]];
        }
        if(adj[x].size()==0){
            ans[x]=x;
            return q[x];
        }
        int mi=q[x];
        for(auto a:adj[x]){
            mi=min(mi,check(a,m,adj,q,ans,rq));
        }
        ans[x]=rq[mi];
        return mi;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& q) {
        int m=q.size();
        vector<int> adj[m];
        for(int i=0;i<richer.size();i++){
            adj[richer[i][1]].push_back(richer[i][0]);
        }
        vector<int> ans(m,-1);
        vector<int> rq(m);
        for(int i=0;i<m;i++){
            rq[q[i]]=i;
        }
        for(int i=0;i<m;i++){
            if(ans[i]==-1){
                int a=check(i,m,adj,q,ans,rq);
                ans[i]=rq[a];
            }
        }
        return ans;
        
    }
};