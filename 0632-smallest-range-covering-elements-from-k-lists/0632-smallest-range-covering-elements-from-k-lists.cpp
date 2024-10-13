class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++){
            for(auto x:nums[i]){
                m[x].push_back(i+1);
            }
        }
        auto i=m.begin(),j=m.begin();
        unordered_map<int,int>m2;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        while(j!=m.end()){
            for(auto x:j->second){
                m2[x]++;
            }
            while(m2.size()==nums.size()){
                pq.push({(j->first-i->first),i->first,j->first});
                for(auto x:i->second){
                    m2[x]--;
                    if(m2[x]==0){
                        m2.erase(x);
                    }
                }
                i++;
            }
            j++;
        }
        return {pq.top()[1],pq.top()[2]};
    }
};