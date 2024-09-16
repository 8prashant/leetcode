// class Solution {
// public:
//     int findMinDifference(vector<string>& ti) {
//         int n=ti.size();
//         vector<double>t;
//         for(auto x:ti){
//             string h=x.substr(0,2);
//             string m=x.substr(3);
//             double hh=stoi(h);
//             double mm=stoi(m);
//             mm=mm/60;
//             hh+=mm;
//             t.push_back(hh);
//         }
//         sort(t.begin(),t.end());
//         double a=(t[n-1]-t[0])*60;
//         double b=(24-t[n-1]+t[0])*60;
//         int ans = (int)round(min(a, b));
//         for(int i=1;i<n;i++){
//             a=(t[i]-t[i-1])*60;
//             b=(24-t[i]+t[i-1])*60;
//             double mi=min(a,b);
//             ans = min(ans,(int)round(mi));
//         }
//         return ans;

//     }
// };

// MINUTE
class Solution {
public:
    int findMinDifference(vector<string>& ti) {
        int n=ti.size();
        vector<int>t;
        for(auto x:ti){
            string h=x.substr(0,2);
            string m=x.substr(3);
            double hh=stoi(h);
            double mm=stoi(m);
            hh=hh*60+mm;
            t.push_back(hh);
        }
        sort(t.begin(),t.end());
        int a=(t[n-1]-t[0]);
        int b=(1440-t[n-1]+t[0]);
        int ans = min(a, b);
        for(int i=1;i<n;i++){
            a=(t[i]-t[i-1]);
            b=(1440-t[i]+t[i-1]);
            ans = min({ans,a,b});
        }
        return ans;

    }
};