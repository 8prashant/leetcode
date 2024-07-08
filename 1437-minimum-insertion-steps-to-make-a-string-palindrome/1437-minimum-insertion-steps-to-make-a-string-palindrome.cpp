class Solution {
public:
    int minInsertions(string t1) {
        string t2=t1;
        reverse(t2.begin(),t2.end());
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
        return t1.size()-prev[t2.size()];
        
    }
};