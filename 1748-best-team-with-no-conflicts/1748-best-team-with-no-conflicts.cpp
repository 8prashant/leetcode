class Solution {
public:
    int bestTeamScore(std::vector<int>& scores, std::vector<int>& ages) {
        int size = scores.size();
        vector<pair<int, int>> players(size); 

        for (int i = 0; i < size; i++) {
            players[i] = make_pair(scores[i], ages[i]);
        }

        sort(players.begin(), players.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second || (a.second == b.second && a.first < b.first);
        });

        vector<int> dp(size, 0);
        for (int i = 0; i < size; i++) {
            dp[i] = players[i].first;
            for (int j = 0; j < i; j++) {
                if (players[i].first >= players[j].first) {
                    dp[i] = max(dp[i], dp[j] + players[i].first);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};