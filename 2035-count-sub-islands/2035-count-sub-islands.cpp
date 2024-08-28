class Solution {
public:
    vector<vector<int>>vis;
    bool check(int x,int y,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        vis[x][y]=1;
        vector<int> dx={-1,1,0,0};
        vector<int> dy={0,0,-1,1};
        bool ans=true;
        if(grid1[x][y]!=1){
            ans=false;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<grid2.size() && ny>=0 && ny<grid2[0].size()&& vis[nx][ny]==-1&&grid2[nx][ny]==1){
                bool res=check(nx,ny,grid1,grid2);
                ans=ans&&res;
            }
        }
        return ans;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vis.resize(grid2.size(),vector<int>(grid2[0].size(),-1));
        int ans=0;
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                if(grid2[i][j]==1 && vis[i][j]==-1){
                    bool res=check(i,j,grid1,grid2);
                    cout<<"i="<<i<<" "<<j<<" "<<res<<endl;
                    if(res==true){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};