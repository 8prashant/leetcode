class Solution {
public:
    int maxFreqSum(const std::string& s) {
        int vowelFreq[5] = {0}; 
        int consonantFreq[26] = {0};

        for (char c : s) {
            if (c == 'a') vowelFreq[0]++;
            else if (c == 'e') vowelFreq[1]++;
            else if (c == 'i') vowelFreq[2]++;
            else if (c == 'o') vowelFreq[3]++;
            else if (c == 'u') vowelFreq[4]++;
            else consonantFreq[c - 'a']++;
        }

        int maxVowel = 0, maxConsonant = 0;
        for (int f : vowelFreq) maxVowel = std::max(maxVowel, f);
        for (int f : consonantFreq) maxConsonant = std::max(maxConsonant, f);

        return maxVowel + maxConsonant;
    }
};