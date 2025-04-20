class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>m;
        int ans=0;
        for(auto x:answers){
            m[x]++;
        }
        for(auto x:m){
            int q=x.second/(x.first+1);
            int r=x.second%(x.first+1);
            ans+=(x.first+1)*q;
            if(r!=0){
                ans+=x.first+1;
            }
        }
        return ans;
    }
};