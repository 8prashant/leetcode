class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> cp(n+1);
        vector<vector<int>> cc(n+1);
        for(auto x:trust){
            cp[x[1]].push_back(x[0]);
            cc[x[0]].push_back(x[1]);
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(cp[i].size()==(n-1) && cc[i].size()==0){
                ans=i;
            }
        }
        return  ans;
    }
};