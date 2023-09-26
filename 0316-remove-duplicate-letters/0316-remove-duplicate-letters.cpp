class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        stack<char>st;
        unordered_set<char> added; // To keep track of characters in the stack
        for(int i=0;i<s.size();i++){
            char c = s[i];
            m[c]--;

            // Skip characters that have already been added to the stack
            if (added.count(c)) {
                continue;
            }

            // Pop characters from the stack as long as:
            // 1. The current character is smaller than the character at the top of the stack.
            // 2. There are more occurrences of the character at the top of the stack later in the string.
            while (!st.empty() && c < st.top() && m[st.top()] > 0) {
                added.erase(st.top());
                st.pop();
            }
            
            st.push(c);
            added.insert(c);
        }
        
        string st1;
        while(!st.empty()){
            st1+=st.top();
            st.pop();
        }
        reverse(st1.begin(), st1.end()); // Reverse to get the correct order
        return st1;
    }
};
