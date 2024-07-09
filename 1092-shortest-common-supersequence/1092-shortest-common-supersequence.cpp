class Solution {
public:
    string shortestCommonSupersequence(string st1, string st2) {
        vector<vector<int>>dp(st1.size()+1,vector<int>(st2.size()+1));
        for(int i=0;i<=st2.size();i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=st1.size();i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=st1.size();i++){
            for(int j=1;j<=st2.size();j++){
                if(st1[i-1]==st2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string ans;
        int i=st1.size(),j=st2.size();
        while(i>=0 && j>=0){
            if(i==0 && j==0){
                break;
            }
            else if(i==0 && j!=0){
                ans=st2.substr(0,j)+ans;
                break;
            }
            else if(j==0 && i!=0){
                ans=st1.substr(0,i)+ans;
                break;
            }
            else{
                if(st1[i-1]==st2[j-1]){
                    ans=st1[i-1]+ans;
                    i--;
                    j--;
                }
                else if(dp[i-1][j]>=dp[i][j-1]){
                    ans=st1[i-1]+ans;
                    i--;
                }
                else{
                    ans=st2[j-1]+ans;
                    j--;
                }
            }
        }

        return ans;
    }
};