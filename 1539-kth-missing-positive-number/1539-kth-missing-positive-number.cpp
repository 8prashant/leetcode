class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans=k;
        for(auto x:arr){
            if(x<=ans){
                ans++;
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};