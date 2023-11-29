class Solution {
public:
    stack<int> sx,sy;
    unordered_map<int,vector<int>> m;
    void dfsx(int a, vector<vector<int>> &x, vector<int> &vis1, stack<int> &sx) {
        vis1[a] = 1;
        for (auto y : x[a]) {
            if (vis1[y] == -1) {
                dfsx(y, x, vis1, sx);
            }
        }
        sx.push(a);
    }

    void dfsy(int a, vector<vector<int>> &y, vector<int> &vis2, stack<int> &sy) {
        vis2[a] = 1;
        for (auto b : y[a]) {
            if (vis2[b] == -1) {
                dfsy(b, y, vis2, sy);
            }
        }
        sy.push(a);
    }

    void topo(vector<vector<int>> &x, vector<vector<int>> &y) {
        vector<int> vis1(x.size(), -1);
        for (int i = 1; i < x.size(); i++) {
            if (vis1[i] == -1) {
                dfsx(i, x, vis1, sx);
            }
        }
        vector<int> vis2(y.size(), -1);
        for (int i = 1; i < y.size(); i++) {
            if (vis2[i] == -1) {
                dfsy(i, y, vis2, sy);
            }
        }
    }

    void dfs(int a, vector<vector<int>> &rx, vector<int> &v, vector<int> &vis) {
        //cout<<"a="<<a<<endl;
        vis[a] = 1;
        v.push_back(a);
        for (auto x : rx[a]) {
            if (vis[x] == -1) {
                dfs(x, rx, v, vis);
            }
        }
    }

    bool check(vector<vector<int>> &x, stack<int> &sx) {
        int n = x.size();
        vector<vector<int>> ans;  // store's all the strongly connected components.
        vector<int> vis(n, -1);
        vector<vector<int>> rx(n);  // reverse graph
        for (int i = 0; i < n; i++) {
            for (auto y : x[i]) {
                rx[y].push_back(i);
            }
        }
        int l=0;
        while (!sx.empty()) {
            int i = sx.top();
            m[i].push_back(l);
            l++;
            //cout<<"i="<<i<<endl;
            sx.pop();
            vector<int> v;
            if (vis[i] == -1) {
                dfs(i, rx, v, vis);
            }
            if(v.size()!=0){
                ans.push_back(v);
            }
        }
        //cout<<"ans="<<ans.size()<<" "<<"n="<<n<<endl;
        return (ans.size() + 1) == n;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> x(k+1),y(k+1),cpx(k+1),cpy(k+1);
        vector<int> vis(k+1),vis2(k+1);
        set<pair<int,int>> setx,sety;

        for(auto v:rowConditions){
            setx.insert({v[0],v[1]});
        }
        for(auto v:colConditions){
            sety.insert({v[0],v[1]});
        }

        for(auto p:setx){
            x[p.second].push_back(p.first);
            cpx[p.first].push_back(p.second);
        }
        for(auto p:sety){
            y[p.second].push_back(p.first);
            cpy[p.first].push_back(p.second);
        }
        topo(x,y);
        // if(check(x,sx)==false){
        //     cout<<"yes"<<endl;
        // }
        if(check(x,sx)==false || check(y,sy)==false){
            cout<<"not"<<endl;
            vector<vector<int>> ans;
            return ans;
        }
        
        // queue<int> q;
        // for(int i=1;i<=k;i++){
        //     vis[i]=cpx[i].size();
        //     if(vis[i]==0){
        //         q.push(i);
        //     }
        // }
        // int l=0;
        // while(!q.empty()){
        //     int size=q.size();
        //     for(int i=0;i<size;i++){
        //         int a=q.front();
        //         q.pop();
        //         m[a].push_back(l);
        //         for(auto g:x[a]){
        //             vis[g]--;
        //             if(vis[g]==0){
        //                 q.push(g);
        //             }
        //         }
        //     }
        //     l++;
        // }
        // //cout<<"m="<<m.size()<<endl;
        // l=0;
        // //vis.clear();
        // for(int i=1;i<=k;i++){
        //     vis2[i]=cpy[i].size();
        //     //cout<<"i="<<i<<" "<<vis2[i]<<endl;
        //     if(vis2[i]==0){
        //         q.push(i);
        //     }
        // }
        // while(!q.empty()){
        //     int size=q.size();
        //     for(int i=0;i<size;i++){
        //         int a=q.front();
        //         //cout<<"a2="<<a<<endl;
        //         q.pop();
        //         m[a].push_back(l);
        //         for(auto g:y[a]){
        //             vis2[g]--;
        //             if(vis2[g]==0){
        //                 q.push(g);
        //             }
        //         }
        //     }
        //     l++;
        // }
        //cout<<"m2="<<m.size()<<endl;
        vector<vector<int>> ans(k,vector<int>(k,0));
        for(auto g:m){
            vector<int> v=g.second;
            //cout<<"si="<<v.size()<<" ";
            if(v.size()>=2){
                int xc=v[0],yc=v[1];
                ans[(k-1)-xc][(k-1)-yc]=g.first;
                cout<<"g="<<g.first<<" "<<xc<<" "<<yc<<endl;
            }
        }
        return ans;
    }
};