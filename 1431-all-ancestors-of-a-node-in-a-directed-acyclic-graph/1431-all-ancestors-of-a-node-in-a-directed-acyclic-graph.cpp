class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>cc(n);
        vector<vector<int>>cp(n);
        for(auto x:edges){
            cc[x[0]].push_back(x[1]);
            cp[x[1]].push_back(x[0]);
        }
        vector<vector<int>> ans(n);
        queue<int>q;
        vector<int>od(n,0);
        for(int i=0;i<n;i++){
            od[i]=cp[i].size();
            if(od[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(auto x:cc[a]){
                od[x]--;
                if(od[x]==0){
                    q.push(x);
                }
            }
            set<int>s;
            for(auto x:cp[a]){
                s.insert(x);
                for(auto y:ans[x]){
                    s.insert(y);
                }
            }
            vector<int>v;
            for(auto x:s){
                v.push_back(x);
            }
            sort(v.begin(),v.end());
            ans[a]=v;
        }
        return ans;

    }
};