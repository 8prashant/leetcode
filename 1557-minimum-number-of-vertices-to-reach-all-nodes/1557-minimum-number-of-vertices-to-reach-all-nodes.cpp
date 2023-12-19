class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> cp(n);
        for(auto x:edges){
            cp[x[1]].push_back(x[0]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(cp[i].size()==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};