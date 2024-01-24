class Solution {
public:
    vector<vector<vector<int>>> dp;
    int dfs(int x1,int y1,int x2,vector<vector<int>>& grid){
        int n=grid.size();
        int y2=(x1+y1)-x2;
        if(x1>=n || y1>=n || x2>=n || y2>=n || grid[x1][y1]==-1 || grid[x2][y2]==-1){
            return -1e8;
        }
        if(x1==n-1 && y1==n-1){
            return grid[n-1][n-1];
        }
        if(dp[x1][y1][x2]!=-1){
            return dp[x1][y1][x2];
        }
        int ans=0;
        if(x1==x2 && y1==y2){
            ans+=grid[x1][y1];
        }
        else{
            ans+=grid[x1][y1]+grid[x2][y2];
        }
        vector<int> dx={1,0};
        vector<int> dy={0,1};
        int res=-1e8;
        for(int i=0;i<2;i++){
            int nx1=x1+dx[i];
            int ny1=y1+dy[i];
            for(int j=0;j<2;j++){
                int nx2=x2+dx[j];
                int ny2=y2+dy[j];
                res=max(res,dfs(nx1,ny1,nx2,grid));
            }
        }
        ans+=res;
        dp[x1][y1][x2]=ans;
        return ans;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        dp.assign(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans=dfs(0,0,0,grid);
        return ans<0?0:ans;
    }
};