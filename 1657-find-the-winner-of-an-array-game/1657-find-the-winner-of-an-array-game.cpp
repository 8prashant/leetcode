/*_1rai*/
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        deque<int> dq(arr.begin(), arr.end());
        int wins = 0;
        int cm = dq.front();
        while (wins < k && wins<n) {
            int a = dq.front();
            dq.pop_front();
            int b = dq.front();
            dq.pop_front();
            if (a > b) {
                dq.push_front(a);
                dq.push_back(b);
                wins++;
            } else {
                dq.push_front(b);
                dq.push_back(a);
                wins = 1;
                cm = b;
            }
        }
        return cm;
    }
};
