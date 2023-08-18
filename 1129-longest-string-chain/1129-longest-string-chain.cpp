class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        int maxChain = 0;

        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        for (auto word : words) {
            int currChain = 1;
            for (int i = 0; i < word.size(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                if (dp[predecessor] > 0) {
                    currChain = max(currChain, dp[predecessor] + 1);
                }
            }
            dp[word] = currChain;
            maxChain = max(maxChain, currChain);
        }

        return maxChain;
    }
};
