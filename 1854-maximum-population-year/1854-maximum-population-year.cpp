class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>m;
        for(auto x:logs){
            m[x[0]]++;
            m[x[1]]--;
        }
        int ma=0,ans;
        int res=0;
        for(auto x:m){
            res+=x.second;
            if(res>ma){
                ma=res;
                ans=x.first;
            }
        }
        return ans;
    }
};