// class Solution {
// public:
//     int ans=0;
//     map<int,int>m;
//     void check(int start,int end){
//         auto it=m.lower_bound(start);
//         while(it!=m.end() && end>=it->second){
//             start=min(start,it->second);
//             end=max(end,it->first);
//             ans-=(it->first-it->second+1);
//             it=m.erase(it);
//         }
//         ans+=end-start+1;
//         m[end]=start;
//     }
//     int numberOfPoints(vector<vector<int>>& nums) {
//         for(auto x:nums){
//             check(x[0],x[1]);
//         }
//         return ans;
//     }
// };

//EASY WAYS
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> v(102,0);
        for(auto x:nums){
            v[x[0]]++;
            v[x[1]+1]--;
        }
        int ans=0,count=0;
        for(int i=1;i<=101;i++){
            count+=v[i];
            if(count>0){
                ans+=1;
            }
        }
        return ans;
    }
};