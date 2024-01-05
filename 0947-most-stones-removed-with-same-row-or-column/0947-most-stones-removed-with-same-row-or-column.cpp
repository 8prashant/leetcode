class Solution {
public:
    unordered_map<int,int> parent;
    int findparent(int u){
        if(parent.find(u)==parent.end() || u==parent[u]){
            return parent[u]=u;
        }
        return parent[u]=findparent(parent[u]);
    }
    int removeStones(vector<vector<int>>& stones) {
        for(auto x:stones){
            int ul_u=findparent(x[0]);
            int ul_v=findparent(100001+x[1]);
            parent[ul_u]=ul_v;
        }
        set<int>s;
        for(auto x:parent){
            int a=findparent(x.first);
            s.insert(a);
        }
        return stones.size()-s.size();

    }
};