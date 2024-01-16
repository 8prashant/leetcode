class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m=og.size(),n=og[0].size();
        if(og[0][0]==1 || og[m-1][n-1]==1){
            return 0;
        }
        vector<vector<int>> ans(m,vector<int>(n,0));
        ans[0][0]=1;
        vector<int> dx={1,0},dy={0,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(og[i][j]==1){
                    continue;
                }
                for(int k=0;k<2;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx<m && ny<n){
                        ans[nx][ny]+=ans[i][j];
                    }
                }
            }
        }
        return ans[m-1][n-1];
    }
};