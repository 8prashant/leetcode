class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& balloons) {
        sort(balloons.begin(), balloons.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<int> balloon = balloons[0];
        int shots = 1;
        for (int i = 1; i < balloons.size(); i++) {
            if (balloons[i][0] <= balloon[1]) {
                continue;
            } else {
                shots++;
                balloon = balloons[i];
            }
        }
        return shots;
    }
};
