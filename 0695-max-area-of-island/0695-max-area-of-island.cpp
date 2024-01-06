class Solution {
public:
    unordered_map<int,int> parent,size;
    int findparent(int u){
        if(parent.find(u)==parent.end() || u==parent[u]){
            return parent[u]=u;
        }
        return parent[u]=findparent(parent[u]);
    }
    void connect(int u, int v){
        int ul_u=findparent(u);
        int ul_v=findparent(v);
        if(ul_u==ul_v){
            return;
        }
        if(size.find(ul_v)==size.end()){
            size[ul_v]++;
        }
        if(size[ul_u]>size[ul_v]){
            parent[ul_v]=ul_u;
            size[ul_u]+=size[ul_v];
        }
        else{
            parent[ul_u]=ul_v;
            size[ul_v]+=size[ul_u];
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,-1,0,1};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    int pa=(grid[i].size()*i)+j;
                    if(size.find(pa)==size.end()){
                        size[pa]++;
                    }
                    for(int k=0;k<4;k++){
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[i].size() && grid[nx][ny]==1){
                            int ch=(grid[i].size()*nx)+ny;
                            connect(pa,ch);
                        }
                    }

                }
            }
        }
        int ans=0;
        for(auto x:size){
            ans=max(ans,x.second);
        }
        return ans;
        
    }
};