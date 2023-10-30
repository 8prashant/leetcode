class Solution {
public:
    bool ans=true;
    void check(vector<vector<int>>& graph,int x,vector<int> &c){
        if(ans==false){
            return;
        }
        int n=graph[x].size();
        for(int i=0;i<n;i++){
            if(c[graph[x][i]]==-1){
                c[graph[x][i]]=!c[x];
                check(graph,graph[x][i],c);
            }
            else if(c[graph[x][i]]!=-1 && c[graph[x][i]]==c[x]){
                ans=false;
                return;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> c(n,-1);
        for(int i = 0; i < n; i++){
            if(c[i] == -1){
                c[i]=1;
                check(graph, i, c);
            }
        }
        return ans;
    }
};