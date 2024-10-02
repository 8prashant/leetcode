class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        map<int,vector<int>>m;
        for(int i=0;i<queries.size();i++){
            m[queries[i]].push_back(i);
        }
        sort(intervals.begin(),intervals.end());
        int i=0;
        vector<int>ans(queries.size(),-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto x:m){
            int n=x.first;
            for(i;i<intervals.size()&& n>=intervals[i][0];i++){
                pq.push({(intervals[i][1]-intervals[i][0]+1),intervals[i][1]});
            }
            while(pq.empty()==false && pq.top().second<n){
                pq.pop();
            }
            if(!pq.empty()){
                for(auto y:x.second){
                    ans[y]=pq.top().first;
                }
            }
        }
        return ans;
    }
};