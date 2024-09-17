class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int ans=0;
        pq.push({0,0,0});
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};
        vector<vector<int>>vis(n,vector<int>(m,-1));
        while(!pq.empty()){
            vector<int>t=pq.top();
            pq.pop();
            ans=max(ans,t[0]);
            if(t[1]==n-1 && t[2]==m-1){
                return ans;
            }
            if(vis[t[1]][t[2]]!=-1){
                continue;
            }
            vis[t[1]][t[2]]=1;
            for(int i=0;i<4;i++){
                int nx=t[1]+dx[i];
                int ny=t[2]+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==-1){
                    pq.push({abs(heights[nx][ny]-heights[t[1]][t[2]]),nx,ny});
                }
            }
        }
        return ans;
    }
};