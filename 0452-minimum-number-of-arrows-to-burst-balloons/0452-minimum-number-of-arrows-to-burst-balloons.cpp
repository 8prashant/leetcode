class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        });
        vector<int> p=points[0];
        int count=1;
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=p[1]){
                continue;
            }
            else{
                count++;
                p=points[i];
            }
        }
        return count;
    }
};