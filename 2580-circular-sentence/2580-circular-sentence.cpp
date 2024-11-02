class Solution {
public:
    bool isCircularSentence(string str) {
        int length = str.size();

        if (str[0] != str[length - 1]) return false;

        for (int index = 1; index < length - 1; index++) {
            if (str[index] == ' ') {
                if (str[index - 1] != str[index + 1]) return false;
            }
        }

        return true;
    }
};
