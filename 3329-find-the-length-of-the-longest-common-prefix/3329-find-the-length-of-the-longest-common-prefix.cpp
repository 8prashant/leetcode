class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int>s;
        for(auto x:arr1){
            int n=x;
            while(n!=0){
                s.insert(n);
                n=n/10;
            }
        }
        int ans=0;
        for(auto x:arr2){
            int n=x;
            while(n!=0){
                int sz=log10(n)+1;
                if(s.find(n)!=s.end()){
                    ans=max(ans,sz);
                }
                n=n/10;
            }
        }
        return ans;
    }
};