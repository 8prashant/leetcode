class Solution {
public:
    void dfs(int a,vector<vector<int>>& rooms,vector<int> &vis){
        vis[a]=1;
        for(auto x:rooms[a]){
            if(vis[x]==-1){
                dfs(x,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,-1);
        dfs(0,rooms,vis);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                return false;
            }
        }
        return true;
    }
};