class Solution {
public:
    vector<int> par,rank;
    int find(int u){
        if(u==par[u]){
            return u;
        }
        return par[u]=find(par[u]);
    }
    void un(int u, int v){
        int ulp_u=find(u);
        int ulp_v=find(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(rank[ulp_u]>rank[ulp_v]){
            par[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v]){
            par[ulp_u]=ulp_v;
        }
        else{
            par[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    un(i,j);
                }
            }
        }
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(find(i));
        }
        return s.size();
    }
};