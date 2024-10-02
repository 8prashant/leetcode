class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,vector<int>>m;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<arr.size();i++){
            if(m.find(arr[i])==m.end()){
                pq.push(arr[i]);
            }
            m[arr[i]].push_back(i);
        }
        int i=1;
        vector<int>ans(arr.size());
        while(!pq.empty()){
            int t=pq.top();
            pq.pop();
            for(auto x:m[t]){
                ans[x]=i;
            }
            i++;
        }
        return ans;
    }
};