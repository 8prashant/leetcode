class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int s,vector<vector<int>>& graph, int t,vector<int> v){
        v.push_back(s);
        if(s==t){
            ans.push_back(v);
            return;
        }
        for(auto x:graph[s]){
            dfs(x,graph,t,v);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size()-1;
        dfs(0,graph,n,{});
        return ans;
    }
};