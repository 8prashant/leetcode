class Solution {
public:
    stack<int>s;
    void trop(int a,vector<int>& edges,vector<int>&vis){
        if(vis[a]!=-1){
            return;
        }
        vis[a]=1;
        if(edges[a]==-1){
            s.push(a);
            return;
        }
        trop(edges[a],edges,vis);
        s.push(a);
        return;
    }
    int dfs(int a,vector<vector<int>>&v,vector<int>&vis){
        if(vis[a]!=-1){
            return 0;
        }
        vis[a]=1;
        int ans=0;
        for(auto x:v[a]){
            if(vis[x]==-1){
                ans+=dfs(x,v,vis);
            }
        }
        return ans+1;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>vis(n,-1);
        vector<vector<int>>v(n);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                trop(i,edges,vis);
            }
            if(edges[i]!=-1){
                v[edges[i]].push_back(i);
            }
        }
        cout<<endl;
        vector<int>vis2(n,-1);
        int ans=1;
        while(!s.empty()){
            int a=s.top();
            s.pop();
            cout<<a<<" "; 
            if(vis2[a]==-1){
                int res=dfs(a,v,vis2);
                ans=max(ans,res);
            }
        }
        return ans==1?-1:ans;
    }
};