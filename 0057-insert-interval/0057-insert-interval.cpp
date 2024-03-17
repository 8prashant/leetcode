class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& existingIntervals, vector<int>& newInterval) {
        vector<vector<int>> mergedIntervals;
        int currentIntervalIndex = 0;

        while (currentIntervalIndex < existingIntervals.size() && existingIntervals[currentIntervalIndex][1] < newInterval[0]) {
            mergedIntervals.push_back(existingIntervals[currentIntervalIndex++]);
        }

        while (currentIntervalIndex < existingIntervals.size() && existingIntervals[currentIntervalIndex][0] <= newInterval[1]) {
            newInterval[0] = min(existingIntervals[currentIntervalIndex][0], newInterval[0]);
            newInterval[1] = max(existingIntervals[currentIntervalIndex][1], newInterval[1]);
            currentIntervalIndex++;
        }

        mergedIntervals.push_back(newInterval);

        while (currentIntervalIndex < existingIntervals.size()) {
            mergedIntervals.push_back(existingIntervals[currentIntervalIndex++]);
        }

        return mergedIntervals;
    }
};
