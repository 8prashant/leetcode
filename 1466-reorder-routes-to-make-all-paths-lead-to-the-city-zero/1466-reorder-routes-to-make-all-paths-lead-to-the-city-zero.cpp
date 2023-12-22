class Solution {
public:
    map<pair<int,int>,int> m;
    int ans=0;
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>graph(n);
        for(auto x:connections){
            m[{x[0],x[1]}]=1;
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,-1);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int size=q.size();
            cout<<size<<endl;
            for(int i=0;i<size;i++){
                int a=q.front();
                vis[a]=1;
                q.pop();
                for(auto x:graph[a]){
                    if(vis[x]==-1){
                        if(m.find({a,x})!=m.end()){
                            ans+=1;
                        }
                        q.push(x);
                    }
                }
            }
        }
        return ans;
    }
};