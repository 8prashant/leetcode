class Solution {
public:
    vector<int> parent,size;
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,-1,0,1};
    int n;
    int findparent(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findparent(parent[u]);
    }
    void dfs(pair<int,int>c,pair<int,int>p,vector<vector<int>>& grid,vector<int> &vis){
        int ch=(n*c.first)+c.second;
        int pa=(n*p.first)+p.second;
        vis[ch]=1;
        parent[ch]=pa;
        if(ch!=pa){
            size[pa]++;
        }
        for(int i=0;i<4;i++){
            int nx=c.first+dx[i];
            int ny=c.second+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                if(grid[nx][ny]==1 && vis[(n*nx)+ny]==-1){
                    dfs({nx,ny},p,grid,vis);
                }
            }
        }
    }
    int check(int x,int y,vector<vector<int>>& grid){
        int ans=0;
        set<int> s;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                if(grid[nx][ny]==1 && s.find(findparent((n*nx)+ny))==s.end()){
                    ans+=size[findparent((n*nx)+ny)];
                    s.insert(findparent((n*nx)+ny));
                }
            }
        }
        return ans+1;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        parent.resize(n*n);
        size.resize(n*n,1);
        for(int i=0;i<n*n;i++){
            parent[i]=i;
        }
        vector<int> vis(n*n,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[(n*i)+j]==-1){
                    dfs({i,j},{i,j},grid,vis);
                    ans=max(ans,size[(n*i)+j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    ans=max(ans,check(i,j,grid));
                    cout<<"ans2="<<ans<<endl;
                }
            }
        }
        return ans;

    }
};