class Solution {
public:
    int numIdenticalPairs(vector<int>& n) {
        unordered_map<int,int> m;
        for(int i=0;i<n.size();i++){
            m[n[i]]++;
        }
        int sum=0;
        for(auto x:m){
            if(x.second>1){
                int n=1;
                int a=x.second;
                for(int i=0;i<2;i++){
                    n=n*a;
                    a--;
                }
                sum+=(n/2);
            }
        }
        return sum;
        
    }
};