//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V,0);
        int ans=0;
        priority_queue<vector<int> , vector<vector<int>> ,greater<vector<int>>> pq;
        pq.push({0,0,-1});
        vector<pair<int,int>> mst;
        while(!pq.empty()){
            vector<int> a=pq.top();
            pq.pop();
            int wi=a[0],no=a[1],pa=a[2];
            if(vis[no]==0){
                vis[no]=1;
                for(auto x:adj[no]){
                    int nod=x[0];
                    int wig=x[1];
                    if(vis[nod]==0){
                        pq.push({wig,nod,no});
                    }
                }
                ans+=wi;
                if(pa!=-1){
                    mst.push_back({pa,no});
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends