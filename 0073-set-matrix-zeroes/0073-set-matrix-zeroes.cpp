class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       set<pair<int,int>> s;
       for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
                s.insert({i,j});
            }
        }
       }
       for(auto x:s){
        for(int j=0;j<matrix[0].size();j++){
            matrix[x.first][j]=0;
        }
        for(int i=0;i<matrix.size();i++){
            matrix[i][x.second]=0;
        }
       }
    }
};