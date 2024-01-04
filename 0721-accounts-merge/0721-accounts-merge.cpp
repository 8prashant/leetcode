class Solution {
public:
    vector<int> parent,rank;
    int findparent(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findparent(parent[u]);
    }
    void connect(int u,int v){
        int po_u=findparent(u);
        int po_v=findparent(v);
        if(po_u==po_v){
            return;
        }
        if(rank[po_u]>rank[po_v]){
            parent[po_v]=po_u;
        }
        else if(rank[po_u]<rank[po_v]){
            parent[po_u]=po_v;
        }
        else{
            parent[po_v]=po_u;
            rank[po_u]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n=acc.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<string,int> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<acc[i].size();j++){
                if(j==0){
                    continue;
                }
                if(m.find(acc[i][j])==m.end()){
                    m[acc[i][j]]=i;
                }
                else{
                    connect(i,m[acc[i][j]]);
                }
            }
        }
        unordered_map<int,vector<string>>m2;
        for(auto x:m){
            int po_u=findparent(x.second);
            m2[po_u].push_back(x.first);
        }
        vector<vector<string>> ans(m2.size());
        int i=0;
        for(auto x:m2){
            ans[i].push_back(acc[x.first][0]);
            sort(x.second.begin(),x.second.end());
            for(auto y:x.second){
                ans[i].push_back(y);
            }
            i++;
        }
        return ans;
    }
};