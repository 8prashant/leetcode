//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int> sd(V, INT_MAX);
        vector<int> vis(V, 0);
        sd[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        while (!pq.empty()) {
            pair<int, int> t = pq.top();
            int a = t.second;
            pq.pop();
            if (vis[a]) continue; // Skip if the vertex has already been visited
            vis[a] = 1;
            for (auto x : adj[a]) {
                int node = x[0];
                int weight = x[1];
                if (sd[node] > sd[a] + weight) {
                    sd[node] = sd[a] + weight;
                    pq.push({sd[node], node});
                }
            }
        }
        return sd;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends