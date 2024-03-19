#include<bits/stdc++.h>
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0){
            return tasks.size();
        }
        unordered_map<char,int>m;
        for(auto x:tasks){
            m[x]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto x:m){
            pq.push({x.second,x.first});
        }
        int ma=pq.top().first;
        pq.pop();
        int ans=(n+1)*(ma-1)+1;
        while(!pq.empty()){
            int t=pq.top().first;
            pq.pop();
            if(t==ma){
                ans++;
            }
            else{
                break;
            }
        }
        ans=max(ans,(int)tasks.size());
        return ans;
    }
};