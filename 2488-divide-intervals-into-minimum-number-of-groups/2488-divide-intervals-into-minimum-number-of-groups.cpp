class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int>m;
        for(auto x:intervals){
            m[x[0]]++;
            m[x[1]+1]--;
        }
        int ans=0;
        int sum=0;
        for(auto x:m){
            sum+=x.second;
            ans=max(ans,sum);
        }
        return ans;
    }
};