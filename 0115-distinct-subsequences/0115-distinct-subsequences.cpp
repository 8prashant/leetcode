class Solution {
public:
    vector<vector<int>> dpp;
    int check(vector<vector<int>> &dp ,string &t1, string &t2,int i,int j , int ma ){
        if(i<=0 || j<=0){
            return 1;
        }
        if(dpp[i][j]!=-1){
            return dpp[i][j];
        }
        int ans=0;
        for(int l=1;l<=i;l++){
            if(dp[l][j]==ma && t1[l-1]==t2[j-1]){
                ans+=check(dp,t1,t2,l-1,j-1,ma-1);
            }
        }
        return dpp[i][j]=ans;
    }


    int numDistinct(string t1, string t2) {
        if(t2.size()>t1.size()){
            return 0;
        }
        vector<vector<int>> dp(t1.size()+1,vector<int>(t2.size()+1,-1));
        for(int i=0;i<=t2.size();i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=t1.size();i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=t1.size();i++){
            for(int j=1;j<=t2.size();j++){
                if(t1[i-1]==t2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        if(dp[t1.size()][t2.size()]!=t2.size()){
            return 0;
        }
        dpp.resize(t1.size()+1,vector<int>(t2.size()+1,-1));
        int ans=check(dp,t1,t2,t1.size(),t2.size(),dp[t1.size()][t2.size()]);
        return ans;
    }
};