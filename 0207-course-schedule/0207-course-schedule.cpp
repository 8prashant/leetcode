class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pr) {
        vector<vector<int>> cp(n);
        vector<vector<int>> cc(n);
        for(int i=0;i<pr.size();i++){
            cp[pr[i][0]].push_back(pr[i][1]);
            cc[pr[i][1]].push_back(pr[i][0]);
        }
        vector<int> vis(n);
        queue<int> q;
        for(int i=0;i<n;i++){
            vis[i]=cp[i].size();;
            if(vis[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            ans.push_back(a);
            for(auto x:cc[a]){
                vis[x]-=1;
                if(vis[x]==0){
                    q.push(x);
                }
            }
        }
        if(ans.size()==n){
            return true;
        }
        return false;
    }
};
