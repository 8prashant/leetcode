//TABULATION with OPTIMIZED SPACE 
class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        vector<int> prev(t2.size()+1,0);
        for(int i=1;i<=t1.size();i++){
            vector<int> curr(t2.size()+1);
            curr[0]=0;
            for(int j=1;j<=t2.size();j++){
                if(t1[i-1]==t2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[t2.size()];
    }
};