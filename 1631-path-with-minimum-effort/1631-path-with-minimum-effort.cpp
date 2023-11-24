class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        int ans=0;
        vector<vector<int>> vis(m,vector<int>(n,-1));
        while(!pq.empty()){
            int we=pq.top()[0];
            int x=pq.top()[1],y=pq.top()[2];
            pq.pop();
            ans=max(ans,we);
            if(x==m-1 && y==n-1){
                return ans;
            }
            vis[x][y]=1;
            vector<int>dx={0,0,1,-1};
            vector<int>dy={1,-1,0,0};
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny]==-1){
                    pq.push({abs(heights[nx][ny]-heights[x][y]),nx,ny});
                }
            }
        }
        return ans;
    }
};