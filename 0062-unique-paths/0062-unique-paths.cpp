class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ans(m,vector<int>(n,0));
        ans[0][0]=1;
        vector<int> dx={1,0};
        vector<int> dy={0,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
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