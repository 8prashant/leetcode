class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0){
            return -1;
        }
        vector<int>dx={0,0,-1,1,-1,1,-1,1};
        vector<int>dy={-1,1,0,0,-1,1,1,-1};
        vector<vector<int>>vis(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        q.push({0,0});
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            ans++;
            for(int i=0;i<s;i++){
                pair<int,int>p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                if(vis[x][y]!=-1){
                    continue;
                }
                if(x==n-1 && y==m-1){
                    return ans;
                }
                vis[x][y]=1;
                for(int i=0;i<8;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m){
                        if(vis[nx][ny]==-1 && grid[nx][ny]==0){
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        return -1;
    }
};