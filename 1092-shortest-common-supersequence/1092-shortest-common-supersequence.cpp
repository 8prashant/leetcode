class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=n,j=m;
        string ans;
        while(i!=0 && j!=0){
            if(s1[i-1]==s2[j-1]){
                ans=s1[i-1]+ans;
                i-=1;
                j-=1;
            }
            else{
                if(dp[i-1][j]>=dp[i][j-1]){
                    ans=s1[i-1]+ans;
                    i-=1;
                }
                else{
                    ans=s2[j-1]+ans;
                    j-=1;
                }
            }
        }
        if(i==0 && j==0){
            return ans;
        }
        if(i==0 && j>0){
            ans=s2.substr(0,j)+ans;
            return ans;
        }
        ans=s1.substr(0,i)+ans;
        return ans;

    }
};