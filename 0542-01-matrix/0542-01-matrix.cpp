class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> v(mat.size(),vector<int>(mat[0].size(),-1));
        queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    v[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int xn=x+dx[i];
                int yn=y+dy[i];
                if(xn>=0 && xn<m && yn>=0 && yn<n && v[xn][yn]==-1){
                    v[xn][yn]=v[x][y]+1;
                    q.push({xn,yn});
                }
            }
        }
        return v;
    }
};