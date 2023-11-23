class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=grid.size(),m=grid.size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1){
            return -1;
        }
        queue<vector<int>>q;
        q.push({0,0,1});
        vector<vector<int>> vis(m,vector<int>(n,-1));
        int ans=-1;
        while(!q.empty()){
            vector<int> v=q.front();
            q.pop();
            int x=v[0],y=v[1],pl=v[2];
            if(x==m-1 &&y==n-1){
                return pl;
            }
            vector<int> dx={-1,-1,-1,0,0,1,1,1};
            vector<int> dy={-1,0,1,-1,1,-1,0,1};
            for(int i=0;i<8;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny]==-1 && grid[nx][ny]==0){
                    vis[nx][ny]=1;
                    q.push({nx,ny,pl+1});
                }
            }
        }
        return ans;
    }
};