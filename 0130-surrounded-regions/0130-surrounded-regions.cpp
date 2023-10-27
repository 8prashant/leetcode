/*
if 0 is connected with corner then can't be surrounded by x so just mark all the 0 connected with the corner rest all will be the x
*/
class Solution {
public:
    void check(vector<vector<char>>& b , pair<int,int>l,vector<vector<int>> &vis){
        int m=b.size() , n=b[0].size();
        int x=l.first,y=l.second;
        if(b[x][y]=='O'){
            vis[x][y]+=1;
        }
        else{
            return;
        }
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,-1,0,1};
        for(int i=0;i<4;i++){
            int xn=x+dx[i],yn=y+dy[i];
            if(xn>=0 && xn<m && yn>=0 && yn<n && b[xn][yn]=='O' && vis[xn][yn]==0){
                check(b,{xn,yn},vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && (i==0 || i==m-1 || j==0 || j==n-1) && vis[i][j]==0){
                    check(board,{i,j},vis);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};