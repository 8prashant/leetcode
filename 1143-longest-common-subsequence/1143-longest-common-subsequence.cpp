class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int m=t1.size();
        int n=t2.size();
        vector<vector<int>> v(m+1 , vector<int>(n+1,-1));
        for(int i=0;i<=m;i++){
            v[i][0]=0;
        }
        for(int i=0;i<=n;i++){
            v[0][i]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(t1[i-1]==t2[j-1]){
                    v[i][j]=1+v[i-1][j-1];
                }
                else{
                    v[i][j]=max(v[i][j-1],v[i-1][j]);
                }
            }
        }
        return v[m][n];
        
    }
};