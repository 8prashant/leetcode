class Solution {
public:
    void mk(vector<vector<char>> & v , int i, int j , int r, int c){
        if(i<0 || i>=r || j<0 || j>=c || v[i][j]!='1'){
            return;
        }
        v[i][j]='2';
        mk(v,i+1,j,r,c);
        mk(v,i-1,j,r,c);
        mk(v,i,j+1,r,c);
        mk(v,i,j-1,r,c);
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        if(r==0){
            return 0;
        }
        int c=grid[0].size();
        int nl=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    mk(grid,i,j,r,c);
                    nl++;
                }
            }
        }
        return nl;
        
    }
};